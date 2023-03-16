/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:51:15 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/14 18:16:30 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	transform_camera(t_camera *c, double **vtm)
{
	c->origin = transform_vector(c->origin, vtm);
	c->orientation = transform_vector(c->orientation, vtm);
}

void	transform_light(t_light *l, double **vtm)
{
	l->origin = transform_vector(l->origin, vtm);
}

void	transform_sphere(t_sphere *s, double **vtm)
{
	s->origin = transform_vector(s->origin, vtm);
}

void	transform_cylinder(t_cylinder *c, double **vtm)
{
	c->origin = transform_vector(c->origin, vtm);
	c->orientation = transform_vector(c->orientation, vtm);
}

void	transform_plane(t_plane *p, double **vtm)
{
	p->origin = transform_vector(p->origin, vtm);
	p->normal = transform_vector(p->normal, vtm);
}
