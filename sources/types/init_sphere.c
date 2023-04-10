/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:57:10 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/10 18:28:52 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	init_sphere(char **attributes, union u_object *object)
{
	int			color;
	t_sphere	*sphere;

	sphere = &object->sphere;
	if (ft_arraylen(attributes) != 3)
		return (err_obj_attr_miss);
	if (get_point(attributes[0], &sphere->origin))
		return (err_obj_attr_value);
	if (!ft_isdouble_str(attributes[1]))
		return (err_obj_attr_value);
	sphere->diameter = ft_atof(attributes[1]);
	color = get_color(attributes[2]);
	if (color == -1)
		return (err_obj_attr_value);
	sphere->color = color;
	return (0);
}
