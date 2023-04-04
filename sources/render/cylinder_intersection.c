/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:11:03 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/04 19:34:02 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <stdio.h>

t_point	get_cylinder_normal(t_intersection intersec, t_cylinder cy, double m);
double calc_a(t_ray ray, t_cylinder cylinder);
double calc_b(t_ray ray, t_cylinder cylinder);
double calc_c(t_ray ray, t_cylinder cylinder);

t_intersection	cylinder_intersection(t_ray r, union u_object object)
{
	t_intersection	intersec;
	t_cylinder		cy;
	double			a;
	double			b;
	double			c;
	double			delta;
	double			t1;
	double			t2;

	cy = object.cylinder;
	intersec.exists = 0;
	a = calc_a(r, cy);
	b = calc_b(r, cy);
	c = calc_c(r, cy);
	delta = (b * b) - 4 * a * c;
	if (delta <= 0)
		return (intersec);
	t1 = (double) ((b * - 1) - sqrt(delta)) / (2 * a);
	t2 = (double) ((b * - 1) + sqrt(delta)) / (2 * a);
	if (t1 > t2)
	{
		double temp = t1;
		t1 = t2;
		t2 = temp;
	}
	double m1 = dot_product(r.orientation, cy.orientation) * t1 + dot_product(vector_dif(r.origin, cy.origin), cy.orientation);
	double m2 = dot_product(r.orientation, cy.orientation) * t2 + dot_product(vector_dif(r.origin, cy.origin), cy.orientation);
	if (t1 < 0.0 || (m1 < 0 || m1 > cy.height))
	{
		if (t2 < 0.0 || (m2 < 0 || m2 > cy.height))
			return (intersec);
		else
		{
			intersec.location = vector_sum(r.origin, vector_scalar(r.orientation, t2));
			intersec.distance = t2;
			intersec.normal = get_cylinder_normal(intersec, cy, m1);
		}
	}
	else
	{
		intersec.location = vector_sum(r.origin, vector_scalar(r.orientation, t1));
		intersec.distance = t1;
		intersec.normal = get_cylinder_normal(intersec, cy, m2);
	}
	intersec.exists = 1;
	intersec.color = cy.color;
	return (intersec);
}

t_point	get_cylinder_normal(t_intersection intersec, t_cylinder cy, double m)
{
	t_point n;	
	t_point x;
	t_point y;

	y = vector_scalar(cy.orientation, m);
	x = vector_dif(intersec.location, cy.origin);
	n = normalize(vector_dif(x, y));
	return (n);
}

double calc_a(t_ray ray, t_cylinder cylinder)
{
	double	x;
	double	y;
	
	x = dot_product(ray.orientation, ray.orientation);
	y = pow(dot_product(ray.orientation, cylinder.orientation), 2);
	return (x - y);
}

double calc_b(t_ray ray, t_cylinder cylinder)
{
	double x;
	double y;
	double z;

	x = dot_product(ray.orientation, vector_dif(ray.origin, cylinder.origin));
	y = dot_product(ray.orientation, cylinder.orientation);
	z = dot_product(vector_dif(ray.origin, cylinder.origin), cylinder.orientation);
	return (2.0 * (x - y * z));
}

double calc_c(t_ray ray, t_cylinder cylinder)
{
	double	x;
	double	y;
	double	z;
	t_point o;

	o = vector_dif(ray.origin, cylinder.origin);
	x = dot_product(o, o);
	y = pow(dot_product(o, cylinder.orientation), 2);
	z = pow(cylinder.diameter / 2.0, 2);
	return (x - y - z);
}
