/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:04:48 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/10 19:54:21 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	init_ambient_light(char **attributes, t_a_light *amb_light)
{
	double	ratio;
	int		color;

	if (ft_arraylen(attributes) != 2)
		return (1);
	if (!ft_isdouble_str(attributes[0]))
		return (1);
	ratio = ft_atof(attributes[0]);
	if (!(ratio >= 0.0 && ratio <= 2.0))
		return (1);
	color = get_color(attributes[1]);
	if (color == -1)
		return (1);
	amb_light->ratio = ratio;
	amb_light->color = color;
	return (0);
}
