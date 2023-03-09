/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:32:20 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/09 17:53:03 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <stdio.h>

int	init_cylinder(char **attributes, union u_element *element)
{
	// 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
	int			attr_len;
	int			color;
	t_cylinder	*cylinder;

	color = 0;
	attr_len = ft_arraylen(attributes);
	cylinder = &element->cylinder;
	if (attr_len != 5)
		return (1);
	if (get_point(attributes[0], &cylinder->origin))
		return (1);
	if (get_point(attributes[1], &cylinder->orientation) && \
		is_normalized(cylinder->orientation))
		return (1);
	if (!ft_isdouble_str(attributes[2]) || !ft_isdouble_str(attributes[3]))
		return (1);
	cylinder->diameter = ft_atof(attributes[2]);
	cylinder->height = ft_atof(attributes[3]);
	color = get_color(attributes[4]);
	if (color == -1)
		return (1);
	cylinder->color = color;
	return (0);
}
