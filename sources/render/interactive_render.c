/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_render.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:15:36 by gcorreia          #+#    #+#             */
/*   Updated: 2023/05/31 22:18:50 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static void				render_px(int x, int y, t_scene *s, t_window *win);
static t_ray			get_px_ray(int x, int y, t_window *win, double fov);

void	interactive_render(t_scene *scene, t_window *win)
{
	int		x;
	int		y;
	int		filler_color;

	x = 0;
	filler_color = 0x000000;
	mlx_clear_window(win->vars.mlx, win->vars.win);
	while (x < win->width)
	{
		y = 0;
		while (y < win->height)
		{
			render_px(x, y, scene, win);
			pixel_put(&win->image, x, y + 1, filler_color);
			pixel_put(&win->image, x, y + 2, filler_color);
			pixel_put(&win->image, x, y + 3, filler_color);
			pixel_put(&win->image, x, y + 4, filler_color);
			y += 4;
		}
		x++;
	}
	win->menu_img_path = "images/Interactive_menu.xpm";
}

static void	render_px(int x, int y, t_scene *s, t_window *win)
{
	t_ray			ray;
	t_intersection	intersec;

	ray = get_px_ray(x, y, win, s->camera->r_fov);
	intersec = get_intersection(ray, s->elements);
	if (intersec.exists)
		pixel_put(&win->image, x, y, intersec.color);
	else
		pixel_put(&win->image, x, y, 0);
}

static t_ray	get_px_ray(int x, int y, t_window *win, double fov)
{
	static double	a_ratio;
	static double	fov_mult;
	t_point	origin;
	t_ray	ray;

	
	if (a_ratio == 0)
	{
		a_ratio = (double)win->width / win->height;
		fov_mult = tan(fov / 2.0);
	}
	origin.x = (2 * ((x + 0.5) / win->width) - 1) * a_ratio * fov_mult;
	origin.y = (1 - 2 * ((y + 0.5) / win->height)) * fov_mult;
	origin.z = 0;
	ray = get_ray(new_point(0, 0, 1), origin);
	ray.origin = origin;
	return (ray);
}
