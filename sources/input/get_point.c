/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:46:58 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/08 15:40:34 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static int	strs_are_valid(char** strs);

int	get_point(char *str, t_point *point)
{
	char	**pts;

	pts = ft_split(str, ',');
	if (!pts || ft_arraylen(pts) != 3 || !strs_are_valid(pts))
	{
		ft_free_array(pts);
		return (1);
	}
	point->x = ft_atof(pts[0]);
	point->y = ft_atof(pts[1]);
	point->z = ft_atof(pts[2]);
	ft_free_array(pts);
	return (0);
}

static int	strs_are_valid(char** strs)
{
	while (*strs)
	{
		if (!ft_isdouble_str(*strs))
			return (0);
		++strs;
	}
	return (1);
}
