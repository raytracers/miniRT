# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:25:00 by lfarias-          #+#    #+#              #
#    Updated: 2023/02/13 15:35:05 by gcorreia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

BUILD = UnitTests/build

ifeq ($(UNAME), Linux)
MINILIBX	= -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX			= mlx_linux
DEFINE		= -D ESC=65307 -D ONE=49 -D TWO=50 -D THREE=51 -D FOUR=52 -D PLUS=61 -D MINUS=45 -D SCRLDWN=5 -D SCRLUP=4
else
MINILIBX	= -Lmlx_mac -lmlx -framework OpenGL -framework appKit
MLX			= mlx_mac
DEFINE		= -D ESC=53 -D ONE=18 -D TWO=19 -D THREE=20 -D FOUR=21 -D PLUS=24 -D MINUS=27 -D SCRLDWN=4 -D SCRLUP=5
endif

$(BUILD):
	@cd UnitTests && cmake -S . -B build

test: $(BUILD)
	@cd UnitTests && cmake --build build && cd build && ctest --output-on-failure
