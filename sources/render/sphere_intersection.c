/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:59:37 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/11 14:56:56 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <stdio.h>

static inline double	get_b(t_ray r, t_sphere s);
static inline double	get_c(t_ray r, t_sphere s);

t_intersection	sphere_intersection(t_ray r, union u_object object)
{
	t_intersection	intersec;
	t_sphere		sphere;
	double			sol;

	sphere = object.sphere;
	intersec.exists = 0;
	sol = quadratic_solver(get_b(r, sphere), get_c(r, sphere));
	if (sol < 0)
		return (intersec);
	intersec.exists = 1;
	intersec.distance = sol;
	intersec.location = vector_sum(r.origin, vector_scalar(r.orientation, sol));
	intersec.normal = normalize(vector_dif(intersec.location, sphere.origin));
	return (intersec);
}

static inline double	get_b(t_ray r, t_sphere s)
{
	return (2 * dot_product(r.orientation, vector_dif(r.origin, s.origin)));
}

static inline double	get_c(t_ray r, t_sphere s)
{
	t_point	oc;

	oc = vector_dif(r.origin, s.origin);
	return (dot_product(oc, oc) - pow(s.diameter / 2, 2));
}
