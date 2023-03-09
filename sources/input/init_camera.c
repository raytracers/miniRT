/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:34:46 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/09 15:53:28 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static int	get_fov(char *str);

int	init_camera(char **attributes, union u_element *element)
{
	t_camera	*camera;

	if (ft_arraylen(attributes) != 3)
		return (1);
	camera = &element->camera;
	if (get_point(attributes[0], &camera->origin)
		|| get_point(attributes[1], &camera->orientation))
	{
		return (1);
	}
	if (!is_normalized(camera->orientation))
		return (1);
	camera->fov = get_fov(attributes[2]);
	if (camera->fov == -1)
		return (1);
	return (0);
}

static int	get_fov(char *str)
{
	int	fov;

	if (!ft_is_digit_str(str))
		return (-1);
	fov = ft_atoi(str);
	if (fov < 0 || fov > 180)
		return (-1);
	return (fov);
}
