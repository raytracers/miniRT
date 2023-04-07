/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_diffuse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:03:13 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/04 16:21:23 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static int	diffuse_red(int p_color, t_light *light, double cs);
static int	diffuse_green(int p_color, t_light *light, double cs);
static int	diffuse_blue(int p_color, t_light *light, double cs);

int	compute_diffuse(t_scene *s, t_ray ld, t_intersection i)
{
	int		r;
	int		g;
	int		b;
	double	cosinus;

	cosinus = dot_product(i.normal, ld.orientation);
	if (cosinus <= 0)
		return (0);
	r = diffuse_red(i.color, s->light, cosinus);
	g = diffuse_green(i.color, s->light, cosinus);
	b = diffuse_blue(i.color, s->light, cosinus);
	return (r << 16 | g << 8 | b);
}

static int	diffuse_red(int p_color, t_light *light, double cs)
{
	int		red;
	double	ratio;

	red = 255 & (p_color >> 16);
	ratio = ((255 & (light->color >> 16)) / 255.0) * light->brightness * cs;
	return (round(red * ratio));
}

static int	diffuse_green(int p_color, t_light *light, double cs)
{
	int		green;
	double	ratio;

	green = 255 & (p_color >> 8);
	ratio = ((255 & (light->color >> 8)) / 255.0) * light->brightness * cs;
	return (round(green * ratio));
}

static int	diffuse_blue(int p_color, t_light *light, double cs)
{
	int		blue;
	double	ratio;

	blue = 255 & p_color;
	ratio = ((255 & light->color) / 255.0) * light->brightness * cs;
	return (round(blue * ratio));
}
