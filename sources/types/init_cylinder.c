/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:32:20 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/21 14:58:01 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	init_cylinder(char **attributes, union u_object *object)
{
	int			color;
	t_cylinder	*cylinder;

	cylinder = &object->cylinder;
	if (ft_arraylen(attributes) != 5)
		return (1);
	if (get_point(attributes[0], &cylinder->origin))
		return (1);
	if (get_point(attributes[1], &cylinder->orientation) || \
		!is_normalized(cylinder->orientation))
		return (1);
	if (!ft_isdouble_str(attributes[2]) || !ft_isdouble_str(attributes[3]))
		return (1);
	cylinder->diameter = ft_atof(attributes[2]);
	cylinder->height = ft_atof(attributes[3]);
	color = get_color(attributes[4]);
	if (color == -1)
		return (1);
	cylinder->color = color;
	cylinder->orientation = normalize(cylinder->orientation);
	return (0);
}
