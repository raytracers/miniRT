/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:15:42 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/10 18:31:31 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	init_plane(char **attributes, union u_object *object)
{
	int			color;
	t_plane		*plane;

	plane = &object->plane;
	if (ft_arraylen(attributes) != 3)
		return (err_obj_attr_miss);
	if (get_point(attributes[0], &plane->origin))
		return (err_obj_attr_value);
	if (get_point(attributes[1], &plane->normal))
		return (err_obj_attr_value);
	if (!is_normalized(plane->normal))
		return (err_obj_attr_value);
	color = get_color(attributes[2]);
	if (color == -1)
		return (err_obj_attr_value);
	plane->color = color;
	plane->normal = normalize(plane->normal);
	return (0);
}
