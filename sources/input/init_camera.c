/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:34:46 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/09 15:15:32 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	init_camera(char **attributes, union u_element *element)
{
	t_camera	*camera;
	camera = &element->camera;
	(void)attributes;
	(void)camera;
	return (0);
}
