/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:39:43 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/16 13:56:59 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <stdlib.h>

static t_point	get_up(t_point d);
static void	init_vtm(double **vtm, t_camera *c);

double	**get_vtm(t_camera *c)
{
	double	**vtm;
	int		i;

	vtm = malloc(sizeof(double **) * 4);
	if (!vtm)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		vtm[i] = malloc(sizeof(double *) * 3);
		if (!vtm[i])
		{
			free_vtm(vtm);
			return (NULL);
		}
		++i;
	}
	init_vtm(vtm, c);
	return (vtm);
}

static void	init_vtm(double **vtm, t_camera *c)
{
	t_point	d;
	t_point	o;
	t_point	r;
	t_point	u;

	d = c->orientation;
	o = c->origin;
	u = get_up(d);
	r = normalize(cross_product(u, d));
	u = cross_product(d, r);
	vtm[0][0] = 0;
	vtm[0][1] = 0;
	vtm[0][2] = 0;
	vtm[0][3] = 0;
	vtm[1][0] = 0;
	vtm[1][1] = 0;
	vtm[1][2] = 0;
	vtm[1][3] = 0;
	vtm[2][0] = 0;
	vtm[2][1] = 0;
	vtm[2][2] = 0;
	vtm[2][3] = 0;
}

static t_point	get_up(t_point d)
{
	t_point	up;

	if (d.y == 1)
		up = new_point(1, 0, 0);
	else
		up = new_point(0, 1, 0);
	return (up);
}

void free_vtm(double **vtm)
{ 
	double	*p;

	if (!vtm)
		return ;
	p = *vtm;
	while (p)
	{
		free(p);
		++p;
	}
}
