/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_px_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:20:07 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/04 16:17:25 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static int	compute_color(t_intersection i, t_scene *s, t_ray l, t_ray v);
static int	compute_r(int a, int d, int s);
static int	compute_g(int a, int d, int s);
static int	compute_b(int a, int d, int s);

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
	int				spec;
	t_intersection	obj;

	(void)v;
	obj = get_intersection(l, s->elements);
	if (obj.exists && obj.distance < get_distance(i.location, s->light->origin))
	{
		spec = 0;
		dif = 0;
	}
	else
	{
		dif = compute_diffuse(s, l, i);
		spec = compute_specular(v.orientation, l.orientation, i.normal, s->light);
	}
	amb = compute_ambient(i, s->a_light);
	return (compute_r(amb, dif, spec) | compute_g(amb, dif, spec) | compute_b(amb, dif, spec));
}

static int	compute_r(int a, int d, int s)
{
	int	red;

	red = 0;
	red = (255 & a >> 16) * 0.1 + (255 & d >> 16) * 0.6 + (255 & s >> 16) * 0.3;
	return (red << 16);
}

static int	compute_g(int a, int d, int s)
{
	int	green;

	green = 0;
	green = (255 & a >> 8) * 0.1 + (255 & d >> 8) * 0.6 + (255 & s >> 8) * 0.3;
	return (green << 8);
}

static int	compute_b(int a, int d, int s)
{
	return ((255 & a) * 0.1 + (255 & d) * 0.6 + (255 & s) * 0.3);
}
