/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:12:54 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/12 21:31:25 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	init_light(char **attributes, t_light **light)
{
	double	brightness;

	if (ft_arraylen(attributes) != 2)
		return (1);
	*light = malloc(sizeof(t_light));
	if (!*light)
		return (1);
	if (get_point(attributes[0], &(*light)->origin))
		return (1);
	if (!ft_isdouble_str(attributes[1]))
		return (1);
	brightness = ft_atof(attributes[1]);
	if (!(brightness >= 0.0 && brightness <= 1.0))
		return (1);
	(*light)->brightness = brightness;
	return (0);
}
