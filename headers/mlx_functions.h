/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:00:40 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/29 11:47:48 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_FUNCTIONS_H
# define MLX_FUNCTIONS_H

# include "types.h"

void	init_window(t_info *info);
void	pixel_put(t_img *img, int x, int y, int color);
int		handle_keypress(int keycode, t_info *info);
int		handle_destroy(t_info *info);

#endif
