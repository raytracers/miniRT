/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:38:29 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/10 14:16:57 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

static void	init_vars(t_window *win);
static void	init_image(t_window *win);

void	init_window(t_window *win)
{
	init_vars(win);
	init_image(win);
}

//Podemos deixar o valor de size dinâmico futuramente
static void	init_vars(t_window *win)
{
	win->width= 800;
	win->height= 800;
	win->vars.mlx = mlx_init();
	win->vars.win = mlx_new_window(win->vars.mlx, win->width,
			win->height, "MiniRT");
	mlx_hook(win->vars.win, 2, 1L << 0, handle_keypress, win);
	mlx_hook(win->vars.win, 17, 0L << 0, handle_destroy, win);
}

static void	init_image(t_window *win)
{
	win->image.img = mlx_new_image(win->vars.mlx, win->width, win->height);
	win->image.addr = mlx_get_data_addr(win->image.img,
			&win->image.bits_per_pixel, &win->image.line_length,
			&win->image.endian);
}
