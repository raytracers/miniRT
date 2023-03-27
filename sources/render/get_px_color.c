/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_px_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:20:07 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/26 21:19:56 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <math.h>

static int	compute_color(t_intersection i, t_scene *s, double cosinus);
static int	compute_blue(t_intersection i, t_scene *s, double cosinus);
static int	compute_green(t_intersection i, t_scene *s, double cosinus);
static int	compute_red(t_intersection i, t_scene *s, double cosinus);

int	get_px_color(t_intersection i, t_scene *s)
{
	double			dist;
	double			cosinus;
	t_intersection	obj;
	t_ray			ray;

	if (!i.exists)
		return (0XAAAAAA);
	dist = get_distance(i.location, s->light->origin);
	ray = get_ray(i.location, s->light->origin);
	ray.origin = vector_sum(ray.origin, vector_scalar(i.normal, 0.0001));
	obj = get_intersection(ray, s->elements);
	if (obj.exists && obj.distance < dist)
		return (0);
	cosinus = dot_product(i.normal, ray.orientation);
	if (cosinus < 0)
		cosinus = 0;
	return (compute_color(i, s, cosinus));
}

static int	compute_color(t_intersection i, t_scene *s, double cosinus)
{
	int	color;

	color = 0;
	color |= compute_blue(i, s, cosinus);
	color |= compute_green(i, s, cosinus) << 8;
	color |= compute_red(i, s, cosinus) << 16;
	return (color);
}

static int	compute_blue(t_intersection i, t_scene *s, double cosinus)
{
	int		b;

	b = 255 & i.color;
	return (round(b * s->light->brightness * cosinus));
}

static int	compute_green(t_intersection i, t_scene *s, double cosinus)
{
	int		g;

	g = 255 & (i.color >> 8);
	return (round(g * s->light->brightness * cosinus));
}

static int	compute_red(t_intersection i, t_scene *s, double cosinus)
{
	int		r;

	r = 255 & (i.color >> 16);
	return (round(r * s->light->brightness * cosinus));
}
