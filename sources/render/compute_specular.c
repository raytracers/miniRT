/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_specular.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:50:18 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/04 16:18:08 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static t_point	reflection_vector(t_point normal, t_point light_dir);

int	compute_specular(t_point v, t_point l, t_point n, t_light *light)
{
	int		red;
	int		green;
	int		blue;
	double	ratio;

	ratio = pow(dot_product(v, reflection_vector(n, l)), 100);
	red = (255 & (light->color >> 16)) * ratio;
	green = (255 & (light->color >> 8)) * ratio;
	blue = (255 & light->color) * ratio;
	return (red << 16 | green << 8 | blue);
}

static t_point	reflection_vector(t_point normal, t_point light_dir)
{
	t_point	result;

	result = vector_scalar(normal, 2 * dot_product(normal, light_dir));
	result = vector_dif(result, light_dir);
	return (result);
}
