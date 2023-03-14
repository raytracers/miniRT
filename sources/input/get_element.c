/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:42:42 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/13 02:30:10 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

enum e_element	get_element(char *elem)
{
	if (elem == NULL)
		return (nae);
	if (!ft_strncmp(elem, "A", 2))
		return (ambient_light);
	else if (!ft_strncmp(elem, "C", 2))
		return (camera);
	else if (!ft_strncmp(elem, "L", 2))
		return (light);
	else if (!ft_strncmp(elem, "sp", 3))
		return (sphere);
	else if (!ft_strncmp(elem, "pl", 3))
		return (plane);
	else if (!ft_strncmp(elem, "cy", 3))
		return (cylinder);
	else
		return (nae);
}
