/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:15:36 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/10 14:37:55 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static void				render_px(int x, int y, t_scene *s, t_window *win);
static t_ray			get_px_ray(int x, int y, t_window *win, double fov);

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
			render_px(x, y, scene, win);
			++y;
		}
		++x;
	}
	win->menu_img_path = "images/Render_menu.xpm";
}

static void	render_px(int x, int y, t_scene *s, t_window *win)
{
	t_ray			ray;
	t_intersection	intersec;
	int				color;

	ray = get_px_ray(x, y, win, s->camera->r_fov);
	intersec = get_intersection(ray, s->elements);
	color = get_px_color(intersec, ray, s);
	pixel_put(&win->image, x, y, color);
}

static t_ray	get_px_ray(int x, int y, t_window *win, double fov)
{
	double	a_ratio;
	double	fov_mult;
	t_point	origin;
	t_ray	ray;

	a_ratio = (double)win->width / win->height;
	fov_mult = tan(fov / 2.0);
	origin.x = (2 * ((x + 0.5) / win->width) - 1) * a_ratio * fov_mult;
	origin.y = (1 - 2 * ((y + 0.5) / win->height)) * fov_mult;
	origin.z = 0;
	ray = get_ray(new_point(0, 0, 1), origin);
	ray.origin = origin;
	return (ray);
}
