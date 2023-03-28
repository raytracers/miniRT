/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:42:24 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/28 03:53:33 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <stdio.h>

t_intersection	plane_intersection(t_ray r, union u_object object)
{
	t_intersection	intersec;
	t_plane			plane;
	double			denom;	
	double			t;
 /* assuming vectors are all normalized
    float denom = dotProduct(n, l);
    if (denom > 1e-6) {
        Vec3f p0l0 = p0 - l0;
        t = dotProduct(p0l0, n) / denom; 
        return (t >= 0);
    } */
	
	// (p0 - l0) * n / l * n
	// p0 - plane origin
	// p  - plane point
	// l0 - ray origin
	// l  - ray direction
	// n - normal
	plane = object.plane;
	intersec.exists = 0;
	denom = dot_product(plane.normal, r.orientation);
	if (denom < 0.000001)
		return (intersec);
	t = (double) dot_product(vector_dif(plane.origin, r.origin), plane.normal) / denom;
	if (t >= 0)
	{
		intersec.exists = 1;
		intersec.distance = t;
		intersec.location = vector_sum(r.origin, vector_scalar(r.orientation, t));
		intersec.normal = normalize(vector_dif(intersec.location, plane.origin));
		intersec.color = plane.color;
	}
	return (intersec);
}
