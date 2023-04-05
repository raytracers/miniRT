/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:42:24 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/04 23:06:07 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <stdio.h>

int	intersects_plane(t_point v1, t_plane plane);

t_intersection	plane_intersection(t_ray r, union u_object object)
{
	t_intersection	intersec;
	t_plane			plane;
	double			denom;	
	double			t;

	plane = object.plane;
	intersec.exists = 0;
	denom = dot_product(plane.normal, r.orientation);
	if (denom < 0.00001 && denom > -0.00001)
		return (intersec);
	t = dot_product(vector_dif(plane.origin, r.origin), plane.normal) / denom;
	if (denom > 0)
		intersec.normal = vector_scalar(plane.normal, -1);
	else
		intersec.normal = plane.normal;
	t = fabs(t);
	intersec.location = vector_sum(r.origin, vector_scalar(r.orientation, t));
	if (intersects_plane(intersec.location, plane))
	{
		intersec.exists = 1;
		intersec.distance = t;
		intersec.color = plane.color;
	}
	return (intersec);
}

int	intersects_plane(t_point v1, t_plane plane)
{	
	t_point	point;
	double	dot_p;

	if (vector_equality(v1, plane.origin))
		return (1);
	point = normalize(vector_dif(v1, plane.origin));
	dot_p = dot_product(plane.normal, point);
	if (dot_p < 0.000001 && dot_p > -0.000001)
		return (1);
	return (0);
}
