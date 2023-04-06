/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:11:03 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/06 15:59:56 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

t_point			get_cylinder_normal(t_point p, t_cylinder cy, double m);
t_intersection	check_cap_intr(t_ray ray, t_cylinder cy);
t_intersection	body_intr(t_ray r, t_cylinder cy, double *t);
t_intersection	get_intr(t_intersection *intr);

t_intersection	cylinder_intersection(t_ray r, union u_object object)
{
	t_intersection	intr[2];
	t_intersection	temp_i;
	double			t[2];
	t_cylinder		cy;

	cy = object.cylinder;
	intr[0].exists = 0;
	intr[1].exists = 0;
	if (cylinder_quadratic(r, cy, &t[0], &t[1]) != -1)
		intr[0] = body_intr(r, cy, t);
	intr[1] = check_cap_intr(r, cy);
	temp_i = get_intr(intr);
	temp_i.color = cy.color;
	return (temp_i);
}

t_intersection	body_intr(t_ray r, t_cylinder cy, double *t)
{
	double			m[2];
	int				i;
	t_intersection	intr[2];
	double			dot_rcy;
	t_point			vec_dif_rcy;

	dot_rcy = dot_product(r.orientation, cy.orientation);
	vec_dif_rcy = vector_dif(r.origin, cy.origin);
	m[0] = dot_rcy * t[0] + dot_product(vec_dif_rcy, cy.orientation);
	m[1] = dot_rcy * t[1] + dot_product(vec_dif_rcy, cy.orientation);
	i = -1;
	while (++i < 2)
	{
		intr[i].exists = 0;
		if (t[i] > 0.0 && (m[i] > 0 && m[i] < cy.height))
		{
			intr[i].exists = 1;
			intr[i].location = vector_sum(r.origin, \
				vector_scalar(r.orientation, t[i]));
			intr[i].distance = t[i];
			intr[i].normal = get_cylinder_normal(intr[i].location, cy, m[i]);
		}
	}
	return (get_intr(intr));
}

t_intersection	check_cap_intr(t_ray ray, t_cylinder cy)
{
	double					p;
	union u_object			obj;
	t_intersection			intr[2];
	double					r_squared;

	obj.plane.origin = cy.origin;
	obj.plane.normal = cy.orientation;
	intr[0] = plane_intersection(ray, obj);
	obj.plane.origin = vector_sum(cy.origin, \
		vector_scalar(cy.orientation, cy.height));
	intr[1] = plane_intersection(ray, obj);
	r_squared = pow(cy.diameter / 2.0, 2);
	if (intr[0].exists == 1)
	{
		p = get_distance(intr[0].location, cy.origin);
		if (pow(p, 2) >= r_squared)
			intr[0].exists = 0;
	}
	if (intr[1].exists == 1)
	{
		p = get_distance(intr[1].location, obj.plane.origin);
		if (pow(p, 2) >= r_squared)
			intr[1].exists = 0;
	}
	return (get_intr(intr));
}

t_intersection	get_intr(t_intersection *intr)
{
	if (intr[0].exists == 1 && intr[1].exists == 1)
	{
		if (intr[0].distance < intr[1].distance)
			return (intr[0]);
		else
			return (intr[1]);
	}
	if (intr[0].exists)
		return (intr[0]);
	if (intr[1].exists)
		return (intr[1]);
	intr[0].exists = 0;
	return (intr[0]);
}

t_point	get_cylinder_normal(t_point p, t_cylinder cy, double m)
{
	t_point	n;
	t_point	x;
	t_point	y;

	y = vector_scalar(cy.orientation, m);
	x = vector_dif(p, cy.origin);
	n = normalize(vector_dif(x, y));
	return (n);
}
