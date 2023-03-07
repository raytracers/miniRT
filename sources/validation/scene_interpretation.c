/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_interpretation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:42:42 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/07 15:40:46 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static int	incorrect_colors(char **rgb);
static int	is_digit_str(char *str);

enum e_element	get_element(char *elem)
{
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

int	get_color(char *colors)
{
	char	**rgb;

	rgb = ft_split(colors, ',');
	if (ft_arraylen(rgb) != 3 || incorrect_colors(rgb))
	{
		ft_free_array(rgb);
		return (-1);
	}
	return ((ft_atoi(rgb[0]) << 16) | (ft_atoi(rgb[1]) << 8) | ft_atoi(rgb[2]));
}

static int	incorrect_colors(char **rgb)
{
	int	value;

	while (*rgb)
	{
		value = ft_atoi(*rgb);
		if (!is_digit_str(*rgb) || value < 0 || value > 255)
			return (1);
		rgb++;
	}
	return (0);
}

static int	is_digit_str(char *str)
{
	if (!(*str))
		return (0);
	while (ft_isdigit(*str++))
		;
	if (*str)
		return (0);
	return (1);
}
