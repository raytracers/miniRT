/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:59:37 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/11 11:59:54 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

t_intersection	sphere_intersection(t_ray ray, union u_object *object)
{
	t_intersection	point;
	t_sphere		*sphere;

	(void)point;
	(void)sphere;
	(void)ray;
	(void)object;
	point.exists = 0;
	return (point);
}
