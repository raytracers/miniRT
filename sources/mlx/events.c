/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:13:45 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/29 17:49:34 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static void	handle_interactive_key(t_info *info, int keycode);

int	handle_destroy(t_info *info)
{
	mlx_destroy_window(info->w->vars.mlx, info->w->vars.win);
	destroy_scene(info->s);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_info	*info)
{
	static int	in_interactive_mode;

	if (keycode == ESC)
	{
		mlx_destroy_window(info->w->vars.mlx, info->w->vars.win);
		destroy_scene(info->s);
		exit(0);
	}
	if (in_interactive_mode)
	{
		if (keycode == KEY_R)
		{
			in_interactive_mode = 0;
			render_scene(info->s, info->w);
		}
		else
			handle_interactive_key(info, keycode);
	}
	else if (keycode == KEY_I)
	{
		interactive_render(info->s, info->w);
		in_interactive_mode = 1;
	}
	return (0);
}

static void	handle_interactive_key(t_info *info, int keycode)
{
	if (keycode == KEY_W)
		move_foreward(info->s);
	else if (keycode == KEY_S)
		move_back(info->s);
	else if (keycode == KEY_A)
		move_left(info->s);
	else if (keycode == KEY_D)
		move_right(info->s);
	else
		return ;
	interactive_render(info->s, info->w);
}
