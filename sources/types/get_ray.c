/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:31:03 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/11 13:46:29 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

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
