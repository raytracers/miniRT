/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:11:03 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/03 16:28:32 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <stdio.h>

t_point	get_cylinder_normal(t_intersection intersec, t_cylinder cy);
double calc_a(t_ray ray, t_cylinder cylinder);
double calc_b(t_ray ray, t_cylinder cylinder);
double calc_c(t_ray ray, t_cylinder cylinder);

t_intersection	cylinder_intersection(t_ray r, union u_object object)
{
	t_intersection	intersec;
	t_cylinder		cy;
	double			sol;
	double			a_height;

	cy = object.cylinder;
	intersec.exists = 0;
	sol = quadratic_solver(calc_a(r, cy), calc_b(r, cy), calc_c(r, cy));
	if (sol < 0)
		return (intersec);
	intersec.distance = sol;
	intersec.location = vector_sum(r.origin, vector_scalar(r.orientation, sol));
	a_height = dot_product(vector_dif(intersec.location, cy.origin), cy.orientation);	
	if (intersec.location.z > (a_height - (cy.height / 2.0)) && intersec.location.z < ((a_height + (cy.height / 2.0))))
		intersec.exists = 1;
	else
		return (intersec);
	intersec.normal = get_cylinder_normal(intersec, cy);
	intersec.color = cy.color;
	return (intersec);
}

t_point	get_cylinder_normal(t_intersection intersec, t_cylinder cy)
{
	t_point	x;
	t_point y;

	x = vector_dif(intersec.location, cy.origin);
	y = vector_scalar(cy.orientation, dot_product(x, cy.orientation));
	return (normalize(vector_dif(x, y)));
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
	double	x;
	double	y;
	double	z;
	
	x = dot_product(ray.orientation, vector_dif(ray.origin, cylinder.origin));
	y = dot_product(ray.orientation, cylinder.orientation);
	z = dot_product(vector_dif(ray.origin, cylinder.origin), \
		cylinder.orientation);
	return (2.0 * (x - y * z));
}

double calc_c(t_ray ray, t_cylinder cylinder)
{
	double	x;
	double	y;
	double	z;

	x = dot_product(vector_dif(ray.origin, cylinder.origin), \
		vector_dif(ray.origin, cylinder.origin));
	y = pow(dot_product(vector_dif(ray.origin, cylinder.origin), cylinder.orientation), 2);
	z = pow(cylinder.diameter / 2.0, 2);
	return (x - y - z);
}
