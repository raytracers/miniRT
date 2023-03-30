/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:17:31 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/29 16:09:55 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/types.h"

t_point	transform_vector(t_point v, double **m)
{
	t_point	r;

	if (!m)
		return (v);
	r.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3];
	r.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3];
	r.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3];
	return (r);
}
