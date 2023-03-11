/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:48:44 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/11 13:47:55 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

t_point	vector_dif(t_point a, t_point b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_point	vector_sum(t_point a, t_point b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_point	vector_scalar(t_point v, double s)
{
	v.x *= s;
	v.y *= s;
	v.z *= s;
	return (v);
}

double	dot_product(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_point	normalize(t_point v)
{
	double	mag;

	mag = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	v.x = v.x / mag;
	v.y = v.y / mag;
	v.z = v.z / mag;
		return (v);
}
