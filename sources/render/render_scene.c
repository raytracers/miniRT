/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:15:36 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/20 17:32:25 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static void	render_pixel(int x, int y, t_scene *scene, t_window *win);
static t_ray	get_pixel_ray(int x, int y, t_window *win, double r_fov);

void	render_scene(t_scene *scene, t_window *win)
{
	int		x;
	int		y;

	x = 0;
	while (x < win->width)
	{
		y = 0;
		while (y < win->height)
		{
			render_pixel(x, y, scene, win);
			++y;
		}
		++x;
	}
}

static void	render_pixel(int x, int y, t_scene *scene, t_window *win)
{
	t_ray			ray;

	ray = get_pixel_ray(x, y, win, scene->camera->r_fov);
	(void)ray;
	//get closest intersection
	//color pixel accordingly
}

static t_ray	get_pixel_ray(int x, int y, t_window *win, double r_fov)
{
	static double	a_ratio;
	static double	fov_mult;
	t_point			origin;
	t_ray			ray;

	if (!a_ratio && !fov_mult)
	{
		a_ratio = win->width / win->height;
		fov_mult = tan(r_fov / 2);
	}
	origin.x = (2 * ((x + 0.5) / win->width) - 1) * a_ratio * fov_mult;
	origin.y = 1 - 2 * ((y + 0.5) / win->height);
	origin.z = 0;
	ray = get_ray(new_point(0,0,1), origin);
	ray.origin = origin;
	return (ray);
}
