/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:45:58 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/14 15:06:13 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/types.h"

t_point	cross_product(t_point a, t_point b)
{
	t_point	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = (a.x * b.z - a.z * b.x) * -1;
	result.z = (a.x * b.y - a.y * b.x);
	return (result);
}
