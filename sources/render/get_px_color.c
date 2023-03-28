/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_px_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:20:07 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/27 12:35:16 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <math.h>

static int	compute_color(t_intersection i, t_scene *s, double cs);
static int	compute_blue(t_intersection i, t_scene *s, double cs);
static int	compute_green(t_intersection i, t_scene *s, double cs);
static int	compute_red(t_intersection i, t_scene *s, double cs);

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
	cosinus = dot_product(i.normal, ray.orientation);
	if (cosinus < 0 || (obj.exists && obj.distance < dist))
		cosinus = 0;
	return (compute_color(i, s, cosinus));
}

static int	compute_color(t_intersection i, t_scene *s, double cs)
{
	int	color;

	color = 0;
	color |= compute_blue(i, s, cs);
	color |= compute_green(i, s, cs) << 8;
	color |= compute_red(i, s, cs) << 16;
	return (color);
}

static int	compute_blue(t_intersection i, t_scene *s, double cs)
{
	int		point_b;
	double	amb_b;
	double	light_b;

	point_b = 255 & i.color;
	light_b = s->light->brightness * cs;
	if (s->a_light)
		amb_b = ((255 & s->a_light->color) / 255.0) * s->a_light->ratio;
	else
		amb_b = 0;
	return (round(point_b * (amb_b * 0.1 + light_b * 0.9)));
}

static int	compute_green(t_intersection i, t_scene *s, double cs)
{
	int		point_g;
	double	amb_g;
	double	light_g;

	point_g = 255 & i.color >> 8;
	light_g = s->light->brightness * cs;
	if (s->a_light)
		amb_g = ((255 & (s->a_light->color >> 8)) / 255.0) * s->a_light->ratio;
	else
		amb_g = 0;
	return (round(point_g * (amb_g * 0.1 + light_g * 0.9)));
}

static int	compute_red(t_intersection i, t_scene *s, double cs)
{
	int		point_r;
	double	amb_r;
	double	light_r;

	point_r = 255 & i.color >> 16;
	light_r = s->light->brightness * cs;
	if (s->a_light)
		amb_r = ((255 & (s->a_light->color >> 16)) / 255.0) * s->a_light->ratio;
	else
		amb_r = 0;
	return (round(point_r * (amb_r * 0.1 + light_r * 0.9)));
}
