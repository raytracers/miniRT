/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:32:20 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/10 18:31:13 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	init_cylinder(char **attributes, union u_object *object)
{
	int			color;
	t_cylinder	*cylinder;

	cylinder = &object->cylinder;
	if (ft_arraylen(attributes) != 5)
		return (err_obj_attr_miss);
	if (get_point(attributes[0], &cylinder->origin))
		return (err_obj_attr_value);
	if (get_point(attributes[1], &cylinder->orientation) || \
		!is_normalized(cylinder->orientation))
		return (err_obj_attr_value);
	if (!ft_isdouble_str(attributes[2]) || !ft_isdouble_str(attributes[3]))
		return (err_obj_attr_fmt);
	cylinder->diameter = ft_atof(attributes[2]);
	cylinder->height = ft_atof(attributes[3]);
	color = get_color(attributes[4]);
	if (color == -1)
		return (err_obj_attr_value);
	cylinder->color = color;
	cylinder->orientation = normalize(cylinder->orientation);
	return (0);
}
