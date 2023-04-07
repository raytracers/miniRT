/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_quadratic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:12:19 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/07 22:57:18 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

double	cone_a(t_ray ray, t_cylinder cylinder, double k);
double	cone_b(t_ray ray, t_cylinder cylinder, double k);
double	cone_c(t_ray ray, t_cylinder cylinder, double k);
void	swap_sols(double *t1, double *t2);

int	cone_quadratic(t_ray ray, t_cylinder cy, double *t1, double *t2)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	k;

	k = atan((cy.diameter / 2.0) / (double) cy.height);
	a = cone_a(ray, cy, k);
	b = cone_b(ray, cy, k);
	c = cone_c(ray, cy, k);
	delta = (b * b) - 4 * a * c;
	if (delta < 0)
		return (-1);
	*t1 = (double)((b * -1) - sqrt(delta)) / (2 * a);
	*t2 = (double)((b * -1) + sqrt(delta)) / (2 * a);
	swap_sols(t1, t2);
	return (0);
}

double	cone_a(t_ray ray, t_cylinder cylinder, double k)
{
	double	x;
	double	y;

	x = dot_product(ray.orientation, ray.orientation);
	y = pow(dot_product(ray.orientation, cylinder.orientation), 2);
	return (x - (1 + pow(k, 2)) * y);
}

double	cone_b(t_ray ray, t_cylinder cylinder, double k)
{
	double	x;
	double	y;
	double	z;

	x = dot_product(ray.orientation, vector_dif(ray.origin, cylinder.origin));
	y = dot_product(ray.orientation, cylinder.orientation);
	z = dot_product(vector_dif(ray.origin, cylinder.origin), \
		cylinder.orientation);
	return (2 * (x - (1 + pow(k, 2)) * y * z));
}

double	cone_c(t_ray ray, t_cylinder cylinder, double k)
{
	t_point	o;
	double	x;
	double	y;

	o = vector_dif(ray.origin, cylinder.origin);
	x = dot_product(o, o);
	y = pow(dot_product(o, cylinder.orientation), 2);
	return (x - (1 + pow(k, 2)) * y);
}

void	swap_sols(double *t1, double *t2)
{
	double	temp;

	if (*t1 > *t2)
	{
		temp = *t1;
		*t1 = *t2;
		*t2 = temp;
	}
}
