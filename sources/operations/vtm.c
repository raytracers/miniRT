/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:39:43 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/21 14:51:32 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static void	init_vtm(double **vtm, double **rtm, t_point o);

double	**get_vtm(double **rtm, t_camera *c)
{
	double	**vtm;
	int		i;

	vtm = ft_calloc(4, sizeof(double *));
	if (!vtm)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		vtm[i] = ft_calloc(4, sizeof(double));
		if (!vtm[i])
		{
			free_matrix(vtm);
			return (NULL);
		}
		++i;
	}
	init_vtm(vtm, rtm, c->origin);
	vtm[3] = NULL;
	return (vtm);
}

static void	init_vtm(double **v, double **r, t_point o)
{
	double	ox;
	double	oy;
	double	oz;

	ox = o.x * (-1);
	oy = o.y * (-1);
	oz = o.z * (-1);
	v[0][0] = r[0][0];
	v[0][1] = r[0][1];
	v[0][2] = r[0][2];
	v[0][3] = r[0][0] * ox + r[0][1] * oy + r[0][2] * oz;
	v[1][0] = r[1][0];
	v[1][1] = r[1][1];
	v[1][2] = r[1][2];
	v[1][3] = r[1][0] * ox + r[1][1] * oy + r[1][2] * oz;
	v[2][0] = r[2][0];
	v[2][1] = r[2][1];
	v[2][2] = r[2][2];
	v[2][3] = r[2][0] * ox + r[2][1] * oy + r[2][2] * oz;
}
