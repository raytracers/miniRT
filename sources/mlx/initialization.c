/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:38:29 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/12 21:02:08 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static void	init_vars(t_info *info);
static void	init_image(t_window *win);

void	init_window(t_info *info)
{
	log_msg("building the engine");
	init_vars(info);
	init_image(info->w);
}

static void	init_vars(t_info *info)
{
	info->w->width = 1920;
	info->w->height = 1080;
	info->w->vars.mlx = mlx_init();
	info->w->vars.win = mlx_new_window(info->w->vars.mlx, info->w->width,
			info->w->height, "MiniRT");
	mlx_hook(info->w->vars.win, 2, 1L << 0, handle_keypress, info);
	mlx_hook(info->w->vars.win, 17, 0L << 0, handle_destroy, info);
	mlx_loop_hook(info->w->vars.mlx, render_loop, info);
}

static void	init_image(t_window *win)
{
	win->image.img = mlx_new_image(win->vars.mlx, win->width, win->height);
	win->image.addr = mlx_get_data_addr(win->image.img,
			&win->image.bits_per_pixel, &win->image.line_length,
			&win->image.endian);
}
