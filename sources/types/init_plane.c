/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:15:42 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/10 11:51:47 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	init_plane(char **attributes, union u_object *object)
{
	int			attr_len;
	int			color;
	t_plane		*plane;

	color = -1;
	attr_len = ft_arraylen(attributes);
	plane = &object->plane;
	if (attr_len != 3)
		return (1);
	if (get_point(attributes[0], &plane->origin))
		return (1);
	if (get_point(attributes[1], &plane->normal))
		return (1);
	if (!is_normalized(plane->normal))
		return (1);
	color = get_color(attributes[2]);
	if (color == -1)
		return (1);
	plane->color = color;
	return (0);
}
