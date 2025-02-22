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

// TODO find a better way to declare and manage macros
#define NUM_THREADS 4
#define SCREEN_HEIGHT 1020;

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
	
	// on change transform the scene
	mlx_image_to_window(app_data->engine, app_data->image, 0, 0);
	transform_scene(app_data->scene_info);
	render_scene(app_data->scene_info, app_data->image);
	mlx_loop(app_data->engine);
	mlx_terminate(app_data->engine);

	return (0);
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
	app_data->engine = mlx_init(1920, 1080, "MiniRT", true);
	if(!app_data->engine) {
		// error handling logic
	}
	app_data->image = mlx_new_image(app_data->engine, 1920, 1080);
	if (!app_data->image) {
		// error handling logic
	}

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
