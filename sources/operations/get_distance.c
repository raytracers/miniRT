/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:42:32 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/26 17:50:05 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <math.h>

double	get_distance(t_point origin, t_point dest)
{
	t_point	diff;

	diff = vector_dif(origin, dest);
	return (sqrt(pow(diff.x, 2) + pow(diff.y, 2) + pow(diff.z, 2)));
}
