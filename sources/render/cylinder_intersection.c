/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:11:03 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/06 01:06:39 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

t_point			get_cylinder_normal(t_point p, t_cylinder cy, double m);
void			check_cap_intr(t_ray ray, t_cylinder cy, t_intersection *intr);
void			body_intr(t_ray r, t_cylinder cy, t_intersection *i, double *t);
void			init_t(t_intersection *intr);

#include <stdio.h>

t_intersection	cylinder_intersection(t_ray r, union u_object object)
{
	t_intersection	intersec[4];
	t_intersection	intr;
	t_cylinder		cy;
	double			t[2];
	int				i;

	cy = object.cylinder;
	init_t(intersec);
	cylinder_quadratic(r, cy, &t[0], &t[1]);
	body_intr(r, cy, intersec, t);
	check_cap_intr(r, cy, intersec);
	intr = intersec[0];
	i = 1;
	while (i < 4)
	{
		if (intersec[i].exists == 1 && intersec[i].distance < intr.distance)
		{
			intr.exists = 1;
			intr.location = intersec[i].location;
			intr.distance = intersec[i].distance;
			intr.normal = intersec[i].normal;
			intr.color = intersec[i].color;
		}
		i++;
	}
	return (intr);
}

void	body_intr(t_ray r, t_cylinder cy, t_intersection *intr, double *t)
{
	double			m[2];
	int				i;

	intr[0].exists = 0;
	intr[1].exists = 0;
	m[0] = dot_product(r.orientation, cy.orientation) * \
		t[0] + dot_product(vector_dif(r.origin, cy.origin), cy.orientation);
	m[1] = dot_product(r.orientation, cy.orientation) * \
		t[1] + dot_product(vector_dif(r.origin, cy.origin), cy.orientation);
	i = 0;
	while (i < 2)
	{
		if (t[i] > 0.0 && (m[i] > 0 && m[i] < cy.height))
		{
			intr[i].exists = 1;
			intr[i].location = vector_sum(r.origin, \
				vector_scalar(r.orientation, t[i]));
			intr[i].distance = t[i];
			intr[i].normal = get_cylinder_normal(intr[i].location, cy, m[i]);
			intr[i].color = cy.color;
		}
		i++;
	}
}

void	check_cap_intr(t_ray ray, t_cylinder cy, t_intersection *intr)
{
	double					p;
	union u_object			obj;
	union u_object			obj2;

	obj.plane.origin = cy.origin;
	//obj.plane.normal = cy.orientation;
	obj.plane.color = cy.color;
	obj.plane.normal = vector_scalar(cy.orientation, -1);
	intr[2] = plane_intersection(ray, obj);
	obj2.plane.origin = vector_sum(cy.origin, \
		vector_scalar(cy.orientation, cy.height));
	//obj2.plane.normal = vector_scalar(cy.orientation, -1);
	obj2.plane.normal = cy.orientation;
	obj2.plane.color = cy.color;
	//obj2.plane.normal = cy.orientation;
	intr[3] = plane_intersection(ray, obj2);
	if (intr[2].exists == 1)
	{
		p = get_distance(intr[2].location, cy.origin);
		if (pow(p, 2) >= pow(cy.diameter / 2.0, 2))
			intr[2].exists = 0;
	}
	if (intr[3].exists == 1)
	{
		p = get_distance(intr[3].location, obj2.plane.origin);
		if (pow(p, 2) >= pow(cy.diameter / 2.0, 2))
			intr[3].exists = 0;
	}
}

void init_t(t_intersection *intr)
{
	int i = 0;

	while (i < 4)
	{
		intr[i].exists = 0;
		intr[i].distance = 0;
		intr[i].color = 0;
		i++;
	}
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
