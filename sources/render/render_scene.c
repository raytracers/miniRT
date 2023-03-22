/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:15:36 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/22 12:29:31 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static void				render_px(int x, int y, t_scene *s, t_window *win);
static void				color_px(int x, int y, t_intersection i, t_window *win);
static t_ray			get_px_ray(int x, int y, t_window *win, double fov);
static t_intersection	get_intersection(t_ray ray, t_elist *e);

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
	mlx_put_image_to_window(win->vars.mlx, win->vars.win, win->image.img, 0, 0);
}

static void	render_px(int x, int y, t_scene *s, t_window *win)
{
	t_ray			ray;
	t_intersection	intersec;

	ray = get_px_ray(x, y, win, s->camera->r_fov);
	intersec = get_intersection(ray, s->elements);
	color_px(x, y, intersec, win);
}

static t_ray	get_px_ray(int x, int y, t_window *win, double fov)
{
	double	a_ratio;
	double	fov_mult;
	t_point			origin;
	t_ray			ray;

	a_ratio = (double)win->width / win->height;
	fov_mult = tan(fov / 2.0);
	origin.x = (2 * ((x + 0.5) / win->width) - 1) * a_ratio * fov_mult;
	origin.y = (1 - 2 * ((y + 0.5) / win->height)) * fov_mult;
	origin.z = 0;
	ray = get_ray(new_point(0,0,1), origin);
	ray.origin = origin;
	return (ray);
}

typedef t_intersection (*t_intersec_funcs)(t_ray, union u_object); 

static t_intersection	get_intersection(t_ray ray, t_elist *e)
{
	t_intersection			intersec;
	t_intersection			temp;
	static t_intersec_funcs	fn[3];

	if (*fn == NULL)
	{
		fn[0] = sphere_intersection;
		fn[1] = NULL;
		fn[2] = NULL;
	}
	intersec.exists = 0;
	while (e)
	{
		temp = fn[e->type](ray, e->object);
		if (!intersec.exists && temp.exists)
			intersec = temp;
		else if (temp.exists && temp.distance < intersec.distance)
			intersec = temp;
		e = e->next;
	}
	return (intersec);
}

static void	color_px(int x, int y, t_intersection i, t_window *win)
{
	if (i.exists)
		pixel_put(&win->image, x, y, i.color);
	else
		pixel_put(&win->image, x, y, 0);
}
