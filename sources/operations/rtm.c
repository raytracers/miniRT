/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:47:22 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/21 14:51:10 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <math.h>

static void	init_rtm(double **m, t_camera *cam);
static void	z_aligned(double **rtm, double orientation);

double	**get_rtm(t_camera *c)
{
	double	**rtm;
	int		i;

	rtm = ft_calloc(4, sizeof(double *));
	if (!rtm)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		rtm[i] = ft_calloc(4, sizeof(double));
		if (!rtm[i])
		{
			free_matrix(rtm);
			return (NULL);
		}
		++i;
	}
	if (c->orientation.z != 1 && c->orientation.z != -1)
		init_rtm(rtm, c);
	else
		z_aligned(rtm, c->orientation.z);
	rtm[3] = NULL;
	return (rtm);
}

static void	init_rtm(double **m, t_camera *cam)
{
	t_point	a;
	double	c;
	double	s;

	a = normalize(cross_product(new_point(0, 0, -1), cam->orientation));
	c = dot_product(cam->orientation, new_point(0, 0, -1));
	s = sqrt(1 - pow(c, 2)) * -1;
	m[0][0] = c + pow(a.x, 2) * (1 - c);
	m[0][1] = a.x * a.y * (1 - c) - a.z * s;
	m[0][2] = a.x * a.z * (1 - c) + a.y * s;
	m[0][3] = 0;
	m[1][0] = a.x * a.y * (1 - c) + a.z * s;
	m[1][1] = c + pow(a.y, 2) * (1 - c);
	m[1][2] = a.y * a.z * (1 - c) - a.x * s;
	m[1][3] = 0;
	m[2][0] = a.x * a.z * (1 - c) - a.y * s;
	m[2][1] = a.y * a.z * (1 - c) + a.x * s;
	m[2][2] = c + pow(a.z, 2) * (1 - c);
	m[2][3] = 0;
}

static void	z_aligned(double **rtm, double orientation)
{
	rtm[0][0] = 1;
	rtm[0][1] = 0;
	rtm[0][2] = 0;
	rtm[0][3] = 0;
	rtm[1][0] = 0;
	rtm[1][1] = 1;
	rtm[1][2] = 0;
	rtm[1][3] = 0;
	rtm[2][0] = 0;
	rtm[2][1] = 0;
	if (orientation == 1)
		rtm[2][2] = -1;
	else
		rtm[2][2] = 1;
	rtm[2][3] = 0;
}
