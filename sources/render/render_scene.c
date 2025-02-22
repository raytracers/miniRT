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

static void	render_px(int x, int y, t_scene *s, mlx_image_t *image);
static t_ray	get_px_ray(int x, int y, mlx_image_t *image, double fov);

#define NUM_THREADS 4
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define PIXEL_SIZE 4

void *render_area(void *arg) {
	t_threaddata	*frame_data;

	frame_data = (t_threaddata *)arg;

	for (int y = frame_data->start_y; y < frame_data->end_y; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			render_px(x, y, frame_data->scene, frame_data->image);
		}
	}

	return NULL;
}

void	render_scene(t_scene *scene, mlx_image_t *image)
{
	long		render_start;
	long		render_finish;
	pthread_t	threads[NUM_THREADS];
	t_threaddata	thread_data[NUM_THREADS];
	

	log_msg("doing expensive and really obscure calculations");
	//pthread_barrier_init(&app_data->frame_barrier, NULL, NUM_THREADS + 1);
	int strip_height = SCREEN_HEIGHT / NUM_THREADS;
	render_start = get_currtime_ms();

	for (int i = 0; i < NUM_THREADS; i++) {
		thread_data[i].thread_id = i + 1;
		thread_data[i].start_y = i * strip_height;
		thread_data[i].end_y = (i == NUM_THREADS - 1) ? SCREEN_HEIGHT : (i + 1) * strip_height;
		thread_data[i].scene = scene;
		thread_data[i].image = image;
		pthread_create(&threads[i], NULL, render_area, &thread_data[i]);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	render_finish = get_currtime_ms();
	log_render_time(render_finish - render_start);
}

static void	render_px(int x, int y, t_scene *s, mlx_image_t *image)
{
	t_ray		ray;
	t_intersection	intersec;
	int		color;

	ray = get_px_ray(x, y, image, s->camera->r_fov);
	intersec = get_intersection(ray, s->elements);
	color = get_px_color(intersec, ray, s);
	mlx_put_pixel(image, x, y, color);
}

static t_ray	get_px_ray(int x, int y, mlx_image_t *image, double fov)
{
	double	a_ratio;
	double	fov_mult;
	t_point	origin;
	t_ray	ray;

	a_ratio = (double)image->width / image->height;
	fov_mult = tan(fov / 2.0);
	origin.x = (2 * ((x + 0.5) / image->width) - 1) * a_ratio * fov_mult;
	origin.y = (1 - 2 * ((y + 0.5) / image->height)) * fov_mult;
	origin.z = 0;
	ray = get_ray(new_point(0, 0, 1), origin);
	ray.origin = origin;
	return (ray);
}
