/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_normalized.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:25:08 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/09 14:12:57 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static inline double	magnitude(t_point v);

int	is_normalized(t_point vector)
{
	double	mag;

	mag = magnitude(vector);
	if (mag > 1.001 || mag < 0.999)
		return (0);
	return (1);
}

static inline double	magnitude(t_point v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}
