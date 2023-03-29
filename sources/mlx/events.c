/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:13:45 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/29 11:49:39 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	handle_keypress(int keycode, t_info	*info)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(info->w->vars.mlx, info->w->vars.win);
		destroy_scene(info->s);
		exit(0);
	}
	return (0);
}

int	handle_destroy(t_info *info)
{
	mlx_destroy_window(info->w->vars.mlx, info->w->vars.win);
	destroy_scene(info->s);
	exit(0);
	return (0);
}
