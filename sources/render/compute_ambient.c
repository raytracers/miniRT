/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:51:57 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/04 16:21:09 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static int	ambient_red(int p_color, t_a_light *light);
static int	ambient_green(int p_color, t_a_light *light);
static int	ambient_blue(int p_color, t_a_light *light);

int	compute_ambient(t_intersection intersec, t_a_light *light)
{
	int	r;
	int	g;
	int	b;

	if (!light || !light->ratio)
		return (0);
	r = ambient_red(intersec.color, light);
	g = ambient_green(intersec.color, light);
	b = ambient_blue(intersec.color, light);
	return (r << 16 | g << 8 | b);
}

static int	ambient_red(int p_color, t_a_light *light)
{
	int		red;
	double	ratio;

	red = 255 & (p_color >> 16);
	ratio = ((255 & (light->color >> 16)) / 255.0) * light->ratio;
	return (round(red * ratio));
}

static int	ambient_green(int p_color, t_a_light *light)
{
	int		green;
	double	ratio;

	green = 255 & (p_color >> 8);
	ratio = ((255 & (light->color >> 8)) / 255.0) * light->ratio;
	return (round(green * ratio));
}

static int	ambient_blue(int p_color, t_a_light *light)
{
	int		blue;
	double	ratio;

	blue = 255 & p_color;
	ratio = ((255 & light->color) / 255.0) * light->ratio;
	return (round(blue * ratio));
}
