/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:13:45 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/16 11:39:00 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <string.h>

/*int	handle_destroy(t_info *info)
{
	log_msg("Good Bye :-)");
	mlx_destroy_window(info->w->vars.mlx, info->w->vars.win);
	destroy_scene(info->s, info->scene_fd);
	exit(0);
	return (0);
}*/

void key_hook(mlx_key_data_t keydata, void* param) {
    static struct timespec last_render = {0};
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    double elapsed = (now.tv_sec - last_render.tv_sec) + 
                     (now.tv_nsec - last_render.tv_nsec) / 1e9;

    if (elapsed < 0.1) return; // 100ms cooldown

    t_appdata* app_data = (t_appdata*)param;
    t_camera *camera = app_data->scene_info->camera;
    bool moved = false;

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) {
        app_data->keys[keydata.key] = true;
        if (keydata.key == MLX_KEY_W) { camera->origin.z += 0.1; moved = true; }
        if (keydata.key == MLX_KEY_S) { camera->origin.z -= 0.1; moved = true; }
        if (keydata.key == MLX_KEY_A) { camera->origin.x -= 0.1; moved = true; }
        if (keydata.key == MLX_KEY_D) { camera->origin.x += 0.1; moved = true; }
    }
    if (keydata.action == MLX_RELEASE) {
        app_data->keys[keydata.key] = false;
    }

    pthread_mutex_lock(&app_data->render_mutex);
    if (moved) {
        app_data->rendering_in_progress = true;
        app_data->sample_count = 0; // Reset on movement
        memset(app_data->accum_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * 4 * sizeof(float));
        pthread_mutex_unlock(&app_data->render_mutex);
        trigger_render(app_data);
        pthread_mutex_lock(&app_data->render_mutex);
        app_data->rendering_in_progress = false;
    }
    pthread_mutex_unlock(&app_data->render_mutex);
}
