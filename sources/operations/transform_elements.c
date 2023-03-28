/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:51:15 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/20 11:16:30 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	transform_camera(t_camera *c, double **vtm, double **rtm)
{
	c->origin = transform_vector(c->origin, vtm);
	c->orientation = transform_vector(c->orientation, rtm);
}

void	transform_light(t_light *l, double **vtm)
{
	l->origin = transform_vector(l->origin, vtm);
}

void	transform_sphere(union u_object *o, double **vtm, double **rtm)
{
	o->sphere.origin = transform_vector(o->sphere.origin, vtm);
	(void)rtm;
}

void	transform_cylinder(union u_object *o, double **vtm, double **rtm)
{
	o->cylinder.origin = transform_vector(o->cylinder.origin, vtm);
	o->cylinder.orientation = transform_vector(o->cylinder.orientation, rtm);
}

void	transform_plane(union u_object *o, double **vtm, double **rtm)
{
	o->plane.origin = transform_vector(o->plane.origin, vtm);
	o->plane.normal = transform_vector(o->plane.normal, rtm);
}
