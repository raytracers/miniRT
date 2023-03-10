/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:31:03 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/10 15:15:33 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static inline t_point	normalize(t_point v);
static inline double	magnitude(t_point v);

t_ray	get_ray(t_point origin, t_point destination)
{
	t_ray	ray;
	t_point	orientation;

	ray.origin = origin;
	orientation.x = destination.x - origin.x;
	orientation.y = destination.y - origin.y;
	orientation.z = destination.z - origin.z;
	ray.orientation = normalize(orientation);
	return (ray);
}

static inline t_point	normalize(t_point v)
{
	double	mag;

	mag = magnitude(v);
	v.x = v.x / mag;
	v.y = v.y / mag;
	v.z = v.z / mag;
		return (v);
}

static inline double	magnitude(t_point v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}
