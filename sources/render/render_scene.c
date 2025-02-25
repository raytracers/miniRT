/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:15:36 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/14 18:21:13 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define JITTER_FACTOR 2.0f
#define PIXEL_SIZE 4

static void	render_px(int x, int y, t_appdata *app_data, mlx_image_t *image);
static t_ray	get_px_ray(int x, int y, mlx_image_t *image, t_scene *scene);

void trigger_render(void *arg) {
    t_appdata		*app_data = (t_appdata *)arg;
    struct timespec	start_time;
    struct timespec	end_time;

    app_data = (t_appdata *)arg;

    if (app_data->sample_count >= 32 && !app_data->rendering_in_progress) {
        return;
    }

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    pthread_mutex_lock(&app_data->render_mutex);

    if (app_data->rendering_in_progress || app_data->sample_count >= 32) {
        pthread_mutex_unlock(&app_data->render_mutex);
        return;
    }

    app_data->start_rendering = true;
    app_data->rendering_in_progress = true;
    atomic_store(&app_data->threads_done, 0);
    pthread_cond_broadcast(&app_data->start_render_cond);
    pthread_mutex_unlock(&app_data->render_mutex);

    pthread_mutex_lock(&app_data->render_mutex);

    while (atomic_load(&app_data->threads_done) < NUM_THREADS) {
        pthread_cond_wait(&app_data->frame_ready_cond, &app_data->render_mutex);
    }
    app_data->start_rendering = false;
    app_data->rendering_in_progress = false;

    if (app_data->sample_count == 0) app_data->sample_count = 1;

    if (app_data->sample_count < 32) {
        printf("Triggering next sample, sample_count=%d\n", app_data->sample_count);
        app_data->start_rendering = true;
        pthread_cond_broadcast(&app_data->start_render_cond);
    }

    pthread_mutex_unlock(&app_data->render_mutex);

    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            int idx = (y * SCREEN_WIDTH + x) * 4;
            float scale = 1.0f / app_data->sample_count;
            uint8_t r = (uint8_t)(app_data->accum_buffer[idx] * scale * 255);
            uint8_t g = (uint8_t)(app_data->accum_buffer[idx + 1] * scale * 255);
            uint8_t b = (uint8_t)(app_data->accum_buffer[idx + 2] * scale * 255);
            uint8_t a = (uint8_t)(app_data->accum_buffer[idx + 3] * scale * 255);
            uint32_t color = (a << 24) | (r << 16) | (g << 8) | b;
            mlx_put_pixel(app_data->render_image, x, y, color);
        }
    }

    mlx_image_t *temp = app_data->render_image;
    app_data->render_image = app_data->display_image;
    app_data->display_image = temp;

    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double elapsed = (end_time.tv_sec - start_time.tv_sec) + 
                     (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    double sleep_time = app_data->refresh_interval - elapsed;
    if (sleep_time > 0) {
        struct timespec sleep_ts;
        sleep_ts.tv_sec = (time_t)sleep_time;
        sleep_ts.tv_nsec = (long)((sleep_time - sleep_ts.tv_sec) * 1e9);
        nanosleep(&sleep_ts, NULL);
    }

    if (!app_data->image_displayed || app_data->sample_count < 32) {
        mlx_image_to_window(app_data->engine, app_data->display_image, 0, 0);
        if (app_data->sample_count >= 32) {
            app_data->image_displayed = true;
        }
    }
}

void render_frame_once(t_appdata *app_data) {
    mlx_image_t	*temp;

    pthread_mutex_lock(&app_data->render_mutex);
    app_data->start_rendering = true;
    atomic_store(&app_data->threads_done, 0);
    pthread_cond_broadcast(&app_data->start_render_cond);
    pthread_mutex_unlock(&app_data->render_mutex);

    pthread_mutex_lock(&app_data->render_mutex);

    while (atomic_load(&app_data->threads_done) < NUM_THREADS) {
        pthread_cond_wait(&app_data->frame_ready_cond, &app_data->render_mutex);
    }

    app_data->start_rendering = false;

    // Average and update render_image
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            int idx = (y * SCREEN_WIDTH + x) * 4;
            float scale = 1.0f / app_data->sample_count;
            uint8_t r = (uint8_t)(app_data->accum_buffer[idx] * scale * 255);
            uint8_t g = (uint8_t)(app_data->accum_buffer[idx + 1] * scale * 255);
            uint8_t b = (uint8_t)(app_data->accum_buffer[idx + 2] * scale * 255);
            uint8_t a = (uint8_t)(app_data->accum_buffer[idx + 3] * scale * 255);
            uint32_t color = (a << 24) | (r << 16) | (g << 8) | b;
            mlx_put_pixel(app_data->render_image, x, y, color);
        }
    }

    // Swap images
    temp = app_data->render_image;
    app_data->render_image = app_data->display_image;
    app_data->display_image = temp;
    pthread_mutex_unlock(&app_data->render_mutex);

    mlx_image_to_window(app_data->engine, app_data->display_image, 0, 0);
}


void display_initial_frame(t_appdata *app_data) {
    pthread_mutex_lock(&app_data->render_mutex);
    app_data->sample_count = 0;
    memset(app_data->accum_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * 4 * sizeof(float));
    pthread_mutex_unlock(&app_data->render_mutex);
    render_frame_once(app_data);
}

void* render_area(void* arg) {
	t_threaddata	*thread_data;
	t_appdata	*app_data;

	thread_data = (t_threaddata *)arg;
	app_data = thread_data->app_data;

	while (1) {
		// Wait for the main thread to signal the start of rendering
		pthread_mutex_lock(&app_data->render_mutex);
		while (!app_data->start_rendering) {
		    pthread_cond_wait(&app_data->start_render_cond, &app_data->render_mutex);
		}
		mlx_image_t *current_render_image = app_data->render_image; // Lock buffer
		pthread_mutex_unlock(&app_data->render_mutex);

		for (int y = thread_data->start_y; y < thread_data->end_y; y++) {
			for (int x = 0; x < SCREEN_WIDTH; x++) {
				render_px(x, y, app_data, current_render_image);
			}
		}

		// Signal completion
		int prev_done = atomic_fetch_add(&app_data->threads_done, 1); // Atomic increment
		if (prev_done + 1 == NUM_THREADS) {
		   pthread_mutex_lock(&app_data->render_mutex);
		   app_data->sample_count++; // Increment after full frame
		   pthread_cond_signal(&app_data->frame_ready_cond);
		   pthread_mutex_unlock(&app_data->render_mutex);
		}
	}
	return NULL;
}

static void	render_px(int x, int y, t_appdata *app_data, mlx_image_t *image)
{
	t_ray		ray;
	t_intersection	intersec;
	int		color;
	t_scene		*s;

	(void)image;
	s = app_data->scene_info;
	ray = get_px_ray(x, y, image, s); // s->camera->r_fov);
	intersec = get_intersection(ray, s->elements);
	color = get_px_color(intersec, ray, s);

	float r = ((color >> 16) & 0xFF) / 255.0f;
	float g = ((color >> 8) & 0xFF) / 255.0f;
	float b = (color & 0xFF) / 255.0f;
	float a = 1.0f;

	int idx = (y * SCREEN_WIDTH + x) * 4;
	app_data->accum_buffer[idx] += r;
	app_data->accum_buffer[idx + 1] += g;
	app_data->accum_buffer[idx + 2] += b;
	app_data->accum_buffer[idx + 3] += a;
}

static t_ray	get_px_ray(int x, int y, mlx_image_t *image, t_scene *scene)
{
	static double	a_ratio;
	static double	fov_mult;
	double		jitter_x;
	double		jitter_y;
	double		jx;
	double		jy;
	t_point		origin;
	t_ray		ray;
	bool		initialized = false;

	if (!initialized) {
		a_ratio = (double)image->width / image->height;
		fov_mult = tan(scene->camera->r_fov * 0.5); // Use r_fov, half angle
	}
	
	// Jitter: optimized single rand() call per axis
	jitter_x = (((float)rand() / RAND_MAX) - 0.5f) * JITTER_FACTOR;
	jitter_y = (((float)rand() / RAND_MAX) - 0.5f) * JITTER_FACTOR;

	// Apply jitter to pixel coordinates
	jx = (double)x + jitter_x;
	jy = (double)y + jitter_y;

	// Compute ray target in camera space
	origin.x = (2.0 * ((jx + 0.5) / image->width) - 1.0) * a_ratio * fov_mult;
	origin.y = (1.0 - 2.0 * ((jy + 0.5) / image->height)) * fov_mult;
	origin.z = -1.0; // Camera space target at z=0

	// Generate ray from camera origin to target
	ray = get_ray(scene->camera->origin, origin);
	ray.origin = scene->camera->origin; // Ensure ray starts at camera position

	return ray;
}
