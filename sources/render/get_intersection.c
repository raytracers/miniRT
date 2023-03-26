/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:36:20 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/26 17:36:36 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

typedef t_intersection	(*t_intersec_funcs)(t_ray, union u_object);

t_intersection	get_intersection(t_ray ray, t_elist *e)
{
	t_intersection			intersec;
	t_intersection			temp;
	static t_intersec_funcs	fn[3];

	if (*fn == NULL)
	{
		fn[0] = sphere_intersection;
		fn[1] = NULL;
		fn[2] = NULL;
	}
	intersec.exists = 0;
	ray.origin = vector_sum(ray.origin, vector_scalar(ray.orientation, 0.0001));
	while (e)
	{
		temp = fn[e->type](ray, e->object);
		if (!intersec.exists && temp.exists)
			intersec = temp;
		else if (temp.exists && temp.distance < intersec.distance)
			intersec = temp;
		e = e->next;
	}
	return (intersec);
}
