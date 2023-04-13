/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:07:59 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/13 18:30:29 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	render_loop(void *param)
{
	t_info	*info;
	void	*menu;
	int		x;
	int		y;

	info = (t_info *) param;
	menu = mlx_xpm_file_to_image(info->w->vars.mlx, info->w->menu_img_path,
			&x, &y);
	mlx_put_image_to_window(info->w->vars.mlx, info->w->vars.win,
		info->w->image.img, 0, 0);
	mlx_put_image_to_window(info->w->vars.mlx, info->w->vars.win, menu, 0, 0);
	mlx_destroy_image(info->w->vars.mlx, menu);
	return (0);
}
