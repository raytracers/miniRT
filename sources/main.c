/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:56:33 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/17 11:44:43 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mini_rt.h"

static int	init_scene(t_appdata *scene, char *filepath);
static int	init_engine(t_appdata *app_data);
static int	init_render_loop(t_appdata *app_data);

int	main(int argc, char **argv)
{
	t_scene		scene;
	t_appdata	app_data;

	app_data.scene_info = &scene;
	log_msg("starting application");

	if (!validate_args(argc, argv)) {
		return (1);
	}

	if (init_scene(&app_data, argv[1]) != 0 \
		|| init_engine(&app_data) != 0 \
		|| init_render_loop(&app_data) != 0) {
		
		return (2);
	}

	return (0);
}

static int	init_render_loop(t_appdata *app_data) {
    static bool     keyset[MLX_KEYSET_SIZE] = {0};
    int             strip_height;

    transform_scene(app_data->scene_info);

    pthread_mutex_init(&app_data->render_mutex, NULL);
    pthread_cond_init(&app_data->start_render_cond, NULL);
    pthread_cond_init(&app_data->frame_ready_cond, NULL);
    app_data->keys = keyset;
    app_data->start_rendering = false;
    app_data->rendering_in_progress = false;
    atomic_store(&app_data->threads_done, 0);
	
    strip_height = SCREEN_HEIGHT / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
	app_data->thread_data[i].thread_id = i + 1;
        app_data->thread_data[i].app_data = app_data;
        app_data->thread_data[i].start_y = i * strip_height;
        app_data->thread_data[i].end_y = (i + 1) * strip_height;
        if (i == NUM_THREADS - 1) {
            app_data->thread_data[i].end_y = SCREEN_HEIGHT; // Cover remainder
        }

        pthread_create(&app_data->threads[i], NULL, render_area, &app_data->thread_data[i]);
    }

    display_initial_frame(app_data);
    mlx_key_hook(app_data->engine, key_hook, app_data);
    mlx_loop_hook(app_data->engine, trigger_render, app_data);
    mlx_loop(app_data->engine);

    // Cleanup
    pthread_mutex_lock(&app_data->render_mutex);
    pthread_cond_broadcast(&app_data->frame_ready_cond);
    pthread_mutex_unlock(&app_data->render_mutex);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(app_data->threads[i], NULL);
    }

    pthread_mutex_destroy(&app_data->render_mutex);
    pthread_cond_destroy(&app_data->frame_ready_cond);
    pthread_cond_destroy(&app_data->start_render_cond);
    mlx_delete_image(app_data->engine, app_data->render_image);
    mlx_delete_image(app_data->engine, app_data->display_image);
    free(app_data->accum_buffer);
    mlx_terminate(app_data->engine);

    return (EXIT_SUCCESS);
}

static int	init_scene(t_appdata *app_data, char* filepath)
{
	app_data->scene_info->a_light = NULL;
	app_data->scene_info->light = NULL;
	app_data->scene_info->camera = NULL;
	app_data->scene_info->elements = NULL;
	app_data->scene_fd = scene_open(filepath);

	if (app_data->scene_fd < 0) {
		return (2);
	}

	log_msg("loading the scene elements");

	if (scene_load(app_data->scene_fd, app_data->scene_info) || scene_check(app_data->scene_info))
	{
		destroy_scene(app_data->scene_info, app_data->scene_fd);
		return (3);
	}

	return (0);
}

static int	init_engine(t_appdata *app_data)
{
	log_msg("starting the graphics engine");
	app_data->engine = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "MiniRT", true);
	if(!app_data->engine) {
		// error handling logic
	}
	app_data->render_image = mlx_new_image(app_data->engine, SCREEN_WIDTH, SCREEN_HEIGHT);
	app_data->display_image = mlx_new_image(app_data->engine, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!app_data->display_image) {
		// error handling logic
	}
	app_data->refresh_interval = 1.0 / 60.0; // 60 Hz default, adjust as needed
	app_data->accum_buffer = calloc(SCREEN_WIDTH * SCREEN_HEIGHT * 4, sizeof(float));  
	app_data->sample_count = 0;
	app_data->image_displayed = false;
	return (0);
}

/*static void	init_vars(t_info *info)
{
	info->w->vars.win = mlx_new_window(info->w->vars.mlx, info->w->width,
			info->w->height, "MiniRT");
	mlx_hook(info->w->vars.win, 2, 1L << 0, handle_keypress, info);
	mlx_hook(info->w->vars.win, 17, 0L << 0, handle_destroy, info);
	mlx_loop_hook(info->w->vars.mlx, render_loop, info);
}

static void	init_image(t_window *win)
{
	win->image.img = mlx_new_image(win->vars.mlx, win->width, win->height);
	win->image.addr = mlx_get_data_addr(win->image.img,
			&win->image.bits_per_pixel, &win->image.line_length,
			&win->image.endian);
}*/
