/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:46:58 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/08 15:26:49 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	get_point(char *str, t_point *point)
{
	char	**pts;
	int		i;

	pts = ft_split(str, ',');
	if (!pts)
		return (1);
	if (ft_arraylen(pts) != 3)
	{
		ft_free_array(pts);
		return (1);
	}
	i = 0;
	while (pts[i])
	{
		if (!ft_isdouble_str(pts[i]))
		{
			ft_free_array(pts);
			return (1);
		}
		++i;
	}
	point->x = ft_atof(pts[0]);
	point->y = ft_atof(pts[1]);
	point->z = ft_atof(pts[2]);
	ft_free_array(pts);
	return (0);
}
