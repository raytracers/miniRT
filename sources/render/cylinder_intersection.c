/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:11:03 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/05 19:58:30 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

t_point			get_cylinder_normal(t_intersection i, t_cylinder cy, double m);
t_intersection	check_cap_intersection(t_ray ray, t_cylinder cy);
t_intersection	get_cap_intersection(t_intersection int1, t_intersection int2);
void			body_intr(t_ray r, t_cylinder cy, t_intersection *i, double *t);

t_intersection	cylinder_intersection(t_ray r, union u_object object)
{
	t_intersection	intersec;
	t_cylinder		cy;
	double			t[2];

	cy = object.cylinder;
	intersec.exists = 0;
	if (cylinder_quadratic(r, cy, &t[0], &t[1]) == -1)
		return (intersec);
	body_intr(r, cy, &intersec, t);
	if (!intersec.exists)
	{
		intersec = check_cap_intersection(r, cy);
		if (intersec.exists == 0)
			return (intersec);
	}
	intersec.exists = 1;
	intersec.color = cy.color;
	return (intersec);
}

void	body_intr(t_ray r, t_cylinder cy, t_intersection *i, double *t)
{
	double			m[2];
	double			t_res;
	double			m_res;

	m[0] = dot_product(r.orientation, cy.orientation) * \
		t[0] + dot_product(vector_dif(r.origin, cy.origin), cy.orientation);
	m[1] = dot_product(r.orientation, cy.orientation) * \
		t[1] + dot_product(vector_dif(r.origin, cy.origin), cy.orientation);
	if (t[0] > 0.0 && (m[0] > 0 && m[0] < cy.height))
	{
		t_res = t[0];
		m_res = m[0];
	}
	else if (t[1] > 0.0 && (m[1] > 0 && m[1] < cy.height))
	{
		t_res = t[1];
		m_res = m[1];
	}
	else
		return ;
	i->exists = 1;
	i->location = vector_sum(r.origin, vector_scalar(r.orientation, t_res));
	i->distance = t_res;
	i->normal = get_cylinder_normal(*i, cy, m_res);
}

#include <stdio.h>

t_intersection	check_cap_intersection(t_ray ray, t_cylinder cy)
{
	t_intersection			int1;
	t_intersection			int2;
	double					p;
	union u_object			obj;
	union u_object			obj2;

	obj.plane.origin = cy.origin;
	obj.plane.normal = cy.orientation;
	//obj.plane.normal = vector_scalar(cy.orientation, -1);
	int1 = plane_intersection(ray, obj);
	obj2.plane.origin = vector_sum(cy.origin, \
		vector_scalar(cy.orientation, cy.height));
	obj2.plane.normal = vector_scalar(cy.orientation, -1);
	//obj2.plane.normal = cy.orientation;
	int2 = plane_intersection(ray, obj2);
	if (int1.exists == 1)
	{
		p = get_distance(int1.location, cy.origin);
		if (pow(p, 2) >= pow(cy.diameter / 2.0, 2))
			int1.exists = 0;
	}
	if (int2.exists == 1)
	{
		p = get_distance(int2.location, obj2.plane.origin);
		if (pow(p, 2) >= pow(cy.diameter / 2.0, 2))
			int2.exists = 0;
	}
	return (get_cap_intersection(int1, int2));
}


t_intersection	get_cap_intersection(t_intersection int1, t_intersection int2)
{
	if (int1.exists == 1)
	{	
		return (int1);
	}
	if (int2.exists == 1)
	{
		return (int2);
	}
	int1.exists = 0;
	return (int1);
}

t_point	get_cylinder_normal(t_intersection intersec, t_cylinder cy, double m)
{
	t_point	n;
	t_point	x;
	t_point	y;

	y = vector_scalar(cy.orientation, m);
	x = vector_dif(intersec.location, cy.origin);
	n = normalize(vector_dif(x, y));
	return (n);
}
