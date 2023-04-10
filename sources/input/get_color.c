/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:58:36 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/10 18:33:53 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static int	incorrect_colors(char **rgb);

int	get_color(char *colors)
{
	char	**rgb;
	int		color;

	rgb = ft_split(colors, ',');
	if (ft_arraylen(rgb) != 3 || incorrect_colors(rgb))
	{
		ft_free_array(rgb);
		return (-1);
	}
	color = (ft_atoi(rgb[0]) << 16) | (ft_atoi(rgb[1]) << 8) | ft_atoi(rgb[2]);
	ft_free_array(rgb);
	return (color);
}

static int	incorrect_colors(char **rgb)
{
	int	value;

	while (*rgb)
	{
		value = ft_atoi(*rgb);
		if (!ft_is_digit_str(*rgb) || value < 0 || value > 255)
			return (1);
		rgb++;
	}
	return (0);
}
