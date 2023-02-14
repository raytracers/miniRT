/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:13:45 by gcorreia          #+#    #+#             */
/*   Updated: 2023/02/14 11:23:24 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"


int	handle_keypress(int keycode, t_window *win)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(win->vars.mlx, win->vars.win);
		exit(0);
	}
	return (0);
}

int	handle_destroy(t_window *win)
{
	mlx_destroy_window(win->vars.mlx, win->vars.win);
	exit(0);
	return (0);
}
