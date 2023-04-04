/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_px_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:20:07 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/04 13:35:55 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static int	compute_color(t_intersection i, t_scene *s, t_ray r);
static int	compute_blue(t_intersection i, t_scene *s, double cs);
static int	compute_green(t_intersection i, t_scene *s, double cs);
static int	compute_red(t_intersection i, t_scene *s, double cs);

int	get_px_color(t_intersection i, t_scene *s)
{
	t_ray			ray;

	if (!i.exists)
		return (0);
	ray = get_ray(i.location, s->light->origin);
	ray.origin = vector_sum(ray.origin, vector_scalar(i.normal, 0.0001));
	return (compute_color(i, s, ray));
}

static int	compute_color(t_intersection i, t_scene *s, t_ray r)
{
	int				color;
	double			dist;
	double			cosinus;
	t_intersection	obj;

	dist = get_distance(i.location, s->light->origin);
	obj = get_intersection(r, s->elements);
	cosinus = dot_product(i.normal, r.orientation);
	if (cosinus < 0 || (obj.exists && obj.distance < dist))
		cosinus = 0;
	color = 0;
	color |= compute_blue(i, s, cosinus);
	color |= compute_green(i, s, cosinus) << 8;
	color |= compute_red(i, s, cosinus) << 16;
	return (color);
}

static int	compute_blue(t_intersection i, t_scene *s, double cs)
{
	int		point_b;
	double	amb_b;
	double	blu;

	point_b = 255 & i.color;
	blu = ((255 & s->light->color) / 255.0) * s->light->brightness * cs;
	if (s->a_light)
		amb_b = ((255 & s->a_light->color) / 255.0) * s->a_light->ratio;
	else
		amb_b = 0;
	return (round(point_b * (amb_b * 0.1 + blu * 0.9)));
}

static int	compute_green(t_intersection i, t_scene *s, double cs)
{
	int		point_g;
	double	amb_g;
	double	grn;

	point_g = 255 & i.color >> 8;
	grn = ((255 & (s->light->color >> 8)) / 255.0) * s->light->brightness * cs;
	if (s->a_light)
		amb_g = ((255 & (s->a_light->color >> 8)) / 255.0) * s->a_light->ratio;
	else
		amb_g = 0;
	return (round(point_g * (amb_g * 0.1 + grn * 0.9)));
}

static int	compute_red(t_intersection i, t_scene *s, double cs)
{
	int		point_r;
	double	amb_r;
	double	red;

	point_r = 255 & i.color >> 16;
	red = ((255 & (s->light->color >> 16)) / 255.0) * s->light->brightness * cs;
	if (s->a_light)
		amb_r = ((255 & (s->a_light->color >> 16)) / 255.0) * s->a_light->ratio;
	else
		amb_r = 0;
	return (round(point_r * (amb_r * 0.1 + red * 0.9)));
}
