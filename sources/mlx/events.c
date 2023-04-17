/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:13:45 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/16 11:39:00 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static void	handle_interactive_key(t_info *info, int keycode);
static void	handle_movement(t_info *info, int keycode);
static void	handle_rotation(t_info *info, int keycode);

int	handle_destroy(t_info *info)
{
	log_msg("Good Bye :-)");
	mlx_destroy_window(info->w->vars.mlx, info->w->vars.win);
	destroy_scene(info->s, info->scene_fd);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_info	*info)
{
	static int	in_interactive_mode;

	if (keycode == ESC)
	{
		handle_destroy(info);
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
		log_msg("entering interactive mode");
		interactive_render(info->s, info->w);
		in_interactive_mode = 1;
	}
	return (0);
}

static void	handle_interactive_key(t_info *info, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D || keycode == KEY_SPACE || keycode == KEY_CTRL)
	{
		handle_movement(info, keycode);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_HOOKL
		|| keycode == KEY_HOOKR || keycode == KEY_UP || keycode == KEY_DOWN)
	{
		handle_rotation(info, keycode);
	}
	else
		return ;
	interactive_render(info->s, info->w);
}

static void	handle_movement(t_info *info, int keycode)
{
	if (keycode == KEY_W)
		move_foreward(info->s);
	else if (keycode == KEY_S)
		move_back(info->s);
	else if (keycode == KEY_A)
		move_left(info->s);
	else if (keycode == KEY_D)
		move_right(info->s);
	else if (keycode == KEY_SPACE)
		move_up(info->s);
	else if (keycode == KEY_CTRL)
		move_down(info->s);
}

static void	handle_rotation(t_info *info, int keycode)
{
	if (keycode == KEY_LEFT)
		turn_left(info->s);
	else if (keycode == KEY_RIGHT)
		turn_right(info->s);
	else if (keycode == KEY_HOOKL)
		spin_left(info->s);
	else if (keycode == KEY_HOOKR)
		spin_right(info->s);
	else if (keycode == KEY_UP)
		turn_up(info->s);
	else if (keycode == KEY_DOWN)
		turn_down(info->s);
}
