/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:39:43 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/20 09:43:01 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <math.h>
#include <stdlib.h>

static void	init_vtm(double **vtm, t_camera *c);

double	**get_vtm(t_camera *c)
{
	double	**vtm;
	int		i;

	vtm = malloc(sizeof(double **));
	if (!vtm)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		vtm[i] = malloc(sizeof(double *) * 4);
		if (!vtm[i])
		{
			free_matrix(vtm);
			return (NULL);
		}
		++i;
	}
	init_vtm(vtm, c);
	vtm[3] = NULL;
	return (vtm);
}

static void	init_vtm(double **m, t_camera *cam)
{
	t_point	a;
	t_point	o;
	double	c;
	double	s;

	a = cross_product(new_point(0, 0, 1), cam->orientation);
	o = cam->origin;
	c = dot_product(a, cam->orientation);
	s = sqrt(1 - pow(c, 2));
	m[0][0] = c - c * pow(a.x, 2) + pow(a.x, 2);
	m[0][1] = a.x * a.y - s * a.z - c * a.x * a.y;
	m[0][2] = a.x * a.z - c * a.x * a.z + s * a.y;
	m[0][3] = (o.x * c * pow(a.x, 2) - o.x * c - o.x * pow(a.x, 2))
		+ (o.y * c * a.x * a.y + o.y * s * a.z - o.y * a.x * a.y)
		+ (o.z * c * a.x * a.z - o.z * a.x * a.z - o.z * s * a.y);
	m[1][0] = a.x * a.y + s * a.z - c * a.x * a.y;
	m[1][1] = c - c * pow(a.y, 2) + pow(a.y, 2);
	m[1][2] = a.y * a.z - s * a.x - c * a.y * a.z;
	m[1][3] = (o.x * c * a.x * a.y - o.x * a.x * a.y - o.x * s * a.z)
		+ (o.y * c * pow(a.y, 2) - o.y * pow(a.y, 2) - o.y * c)
		+ (o.z * s * a.x + o.z * c * a.y * a.z - o.z * a.y * a.z);
	m[2][0] = a.x * a.z - c * a.x * a.z - s * a.y;
	m[2][1] = a.y * a.z + s * a.x - c * a.y * a.z;
	m[2][2] = c - c * pow(a.z, 2) + pow(a.z, 2);
	m[2][3] = (o.x * s * a.y + o.x * c * a.x * a.z - o.x * a.x * a.z)
		+ (o.y * c * a.y * a.z - o.y * a.y * a.z - o.y * s * a.x)
		+ (o.z * c * pow(a.z, 2) - o.z * pow(a.z, 2) - o.z * c);
}
