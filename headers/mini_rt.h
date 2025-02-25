/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:26:53 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/04 17:47:54 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "../libs/libft/libft.h"
# include "../libs/mlx42/include/MLX42/MLX42.h"
# include "types.h"
# include "input.h"
# include "error.h"
# include "render.h"
# include "app.h"
# include "operations.h"
# include <stdlib.h>
# include <math.h>

// SCREEN 
#define RES_720_WIDTH 1280
#define RES_720_HEIGHT 720
#define RES_1080_WIDTH 1920
#define RES_1080_HEIGHT 1080

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH RES_720_WIDTH
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT RES_720_HEIGHT
# endif 

#endif
