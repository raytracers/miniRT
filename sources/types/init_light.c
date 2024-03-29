/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:12:54 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/10 18:23:16 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	init_light(char **attributes, t_light **light)
{
	double	brightness;
	int		n_attr;

	n_attr = ft_arraylen(attributes);
	if (n_attr < 2 || n_attr > 3)
		return (err_obj_attr_miss);
	*light = malloc(sizeof(t_light));
	if (!*light)
		return (1);
	if (get_point(attributes[0], &(*light)->origin))
		return (err_obj_attr_value);
	if (!ft_isdouble_str(attributes[1]))
		return (err_obj_attr_fmt);
	brightness = ft_atof(attributes[1]);
	if (!(brightness >= 0.0 && brightness <= 1.0))
		return (err_obj_attr_value);
	(*light)->brightness = brightness;
	if (n_attr == 2)
		(*light)->color = 0XFFFFFF;
	else
		(*light)->color = get_color(attributes[2]);
	if ((*light)->color == -1)
		return (err_obj_attr_value);
	return (0);
}
