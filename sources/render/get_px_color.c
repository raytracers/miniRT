/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_px_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:20:07 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/04 15:06:11 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static int	compute_color(t_intersection i, t_scene *s, t_ray l, t_ray v);
static int	compute_r(int a, int d);
static int	compute_g(int a, int d);
static int	compute_b(int a, int d);

int	get_px_color(t_intersection i, t_ray view_d, t_scene *s)
{
	t_ray			ray;

	if (!i.exists)
		return (0);
	ray = get_ray(i.location, s->light->origin);
	ray.origin = vector_sum(ray.origin, vector_scalar(i.normal, 0.0001));
	return (compute_color(i, s, ray, view_d));
}

static int	compute_color(t_intersection i, t_scene *s, t_ray l, t_ray v)
{
	int				amb;
	int				dif;
	t_intersection	obj;

	(void)v;
	obj = get_intersection(l, s->elements);
	if (obj.exists && obj.distance < get_distance(i.location, s->light->origin))
		dif = 0;
	else
		dif = compute_diffuse(s, l, i);
	amb = compute_ambient(i, s->a_light);
	return (compute_r(amb, dif) | compute_g(amb, dif) | compute_b(amb, dif));
}

static int	compute_r(int a, int d)
{
	int	red;

	red = 0;
	red = (255 & a >> 16) * 0.2 + (255 & d >> 16) * 0.8;
	return (red << 16);
}

static int	compute_g(int a, int d)
{
	int	green;

	green = 0;
	green = (255 & a >> 8) * 0.2 + (255 & d >> 8) * 0.8;
	return (green << 8);
}

static int	compute_b(int a, int d)
{
	return ((255 & a) * 0.2 + (255 & d) * 0.8);
}
