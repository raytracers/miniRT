/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:11:03 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/31 20:48:55 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

double calc_b(t_ray ray);
double calc_c(t_ray ray, t_cylinder cylinder);

t_intersection	cylinder_intersection(t_ray r, union u_object object)
{
	t_intersection	intersec;
	t_cylinder		cylinder;
	double			sol;

	cylinder = object.cylinder;
	intersec.exists = 0;
	sol = quadratic_solver(calc_b(r), calc_c(r, cylinder));
	if (sol < 0)
		return (intersec);
	intersec.exists = 1;
	intersec.distance = sol;
	intersec.location = vector_sum(r.origin, vector_scalar(r.orientation, sol));
	intersec.normal = normalize(vector_dif(intersec.location, cylinder.origin));
	intersec.color = cylinder.color;
	return (intersec);
}

double calc_b(t_ray ray)
{
	double x;
	double y;

	x = ray.origin.x * ray.orientation.x;
	y = ray.origin.y * ray.orientation.y;
	return (2 * (x + y));
}

double calc_c(t_ray ray, t_cylinder cylinder)
{
	return (pow(ray.origin.x,2)	+ pow(ray.origin.y, 2) - pow(cylinder.diameter, 2));
}
