/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:26:39 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/05 12:33:31 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYS_H
# define MLX_KEYS_H	

# ifdef __linux__
#  define ESC 65307
#  define KEY_I 105 
#  define KEY_W 119 
#  define KEY_R 114 
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_UP 65362
#  define KEY_RIGHT 65363
#  define KEY_DOWN 65364
#  define KEY_HOOKL 91
#  define KEY_HOOKR 93
#  define KEY_CTRL 65507
#  define KEY_SPACE 32
# elif __APPLE__
#  define ESC 53
#  define KEY_I 34
#  define KEY_W 13
#  define KEY_R 15
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_DOWN 125
#  define KEY_UP 126
#  define KEY_HOOKL 30
#  define KEY_HOOKR 33
#  define KEY_CTRL 256
#  define KEY_SPACE 49
# endif

#endif //MLX_KEYS_H
