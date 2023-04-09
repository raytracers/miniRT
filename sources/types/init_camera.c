/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:34:46 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/09 15:03:34 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static double	fov_to_rfov(int fov);
static int		get_fov(char *str);

int	init_camera(char **attributes, t_camera **cam)
{
	if (ft_arraylen(attributes) != 3)
		return (1);
	*cam = malloc(sizeof(t_camera));
	if (!*cam)
		return (1);
	if (get_point(attributes[0], &(*cam)->origin)
		|| get_point(attributes[1], &(*cam)->orientation))
		return (1);
	(*cam)->fov = get_fov(attributes[2]);
	if ((*cam)->fov == -1 || !is_normalized((*cam)->orientation))
		return (1);
	(*cam)->r_fov = fov_to_rfov((*cam)->fov);
	(*cam)->orientation = normalize((*cam)->orientation);
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

static double	fov_to_rfov(int fov)
{
	return (fov * (M_PI / 180));
}
