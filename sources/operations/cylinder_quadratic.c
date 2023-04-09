/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_quadratic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:09:12 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/05 03:05:59 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

double	calc_a(t_ray ray, t_cylinder cylinder);
double	calc_b(t_ray ray, t_cylinder cylinder);
double	calc_c(t_ray ray, t_cylinder cylinder);

int	cylinder_quadratic(t_ray ray, t_cylinder cy, double *t1, double *t2)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	temp;

	a = calc_a(ray, cy);
	b = calc_b(ray, cy);
	c = calc_c(ray, cy);
	delta = (b * b) - 4 * a * c;
	if (delta < 0)
		return (-1);
	*t1 = (double)((b * -1) - sqrt(delta)) / (2 * a);
	*t2 = (double)((b * -1) + sqrt(delta)) / (2 * a);
	if (*t1 > *t2)
	{
		temp = *t1;
		*t1 = *t2;
		*t2 = temp;
	}
	return (0);
}

double	calc_a(t_ray ray, t_cylinder cylinder)
{
	double	x;
	double	y;

	x = dot_product(ray.orientation, ray.orientation);
	y = pow(dot_product(ray.orientation, cylinder.orientation), 2);
	return (x - y);
}

double	calc_b(t_ray ray, t_cylinder cylinder)
{
	double	x;
	double	y;
	double	z;

	x = dot_product(ray.orientation, vector_dif(ray.origin, \
		cylinder.origin));
	y = dot_product(ray.orientation, cylinder.orientation);
	z = dot_product(vector_dif(ray.origin, cylinder.origin), \
		cylinder.orientation);
	return (2.0 * (x - y * z));
}

double	calc_c(t_ray ray, t_cylinder cylinder)
{
	double	x;
	double	y;
	double	z;
	t_point	o;

	o = vector_dif(ray.origin, cylinder.origin);
	x = dot_product(o, o);
	y = pow(dot_product(o, cylinder.orientation), 2);
	z = pow(cylinder.diameter / 2.0, 2);
	return (x - y - z);
}
