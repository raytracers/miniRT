/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_px_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:20:07 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/26 17:39:42 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	get_px_color(t_intersection i, t_scene *s)
{
	(void)s;
	int				color;
//	double			cosinus;
//	t_intersection	obj;
//
	color = 0;
	if (!i.exists)
		return (color);
//	obj = get_intersection(get_ray(i.location, s->light->origin), s->elements);
	return (i.color);
}
