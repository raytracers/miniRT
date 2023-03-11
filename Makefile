# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:25:00 by lfarias-          #+#    #+#              #
#    Updated: 2023/03/11 12:45:31 by gcorreia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----PROJECT VARIABLES-----#
NAME	=	miniRT

BUILD	= UnitTests/build

CC		= cc

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

#-----C FILES-----#

INPUT = $(addprefix input/,	\
	arg_validator.c					\
	scene_loader.c					\
	error.c 						\
	get_element.c					\
	get_color.c						\
	get_point.c						\
	is_normalized.c					\
)

TYPES = $(addprefix types/,	\
	t_elist.c				\
	init_camera.c			\
	init_sphere.c			\
	init_cylinder.c			\
	init_plane.c			\
)

RENDER = $(addprefix render/,	\
	sphere_intersection.c		\
)

OPERATIONS = $(addprefix operations/,	\
	quadratic_solver.c					\
)

MY_MLX		= $(addprefix mlx/,	\
	utils.c						\
	initialization.c			\
	events.c					\
)

MAIN 		= main.c

SRCS 		= $(addprefix sources/,	\
	$(MAIN)							\
	$(INPUT)						\
	$(TYPES)						\
	$(RENDER)						\
	$(OPERATIONS)					\
	$(MY_MLX)						\
)

OBJS 		= $(SRCS:.c=.o)

#-----LIBFT VARIABLES-----#
LIBFT_DIR	= libft

LIBFT		= $(LIBFT_DIR)/libft.a

ILIBFT		= -L$(LIBFT_DIR) -lft

#-----MLX VARIABLES-----#
UNAME := $(shell uname -s)

ifeq ($(UNAME), Linux)
MLX_DIR		= mlx_linux
IMLX		= -L$(MLX_DIR) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
DEFINES		= -D ESC=65307 -D ONE=49 -D TWO=50 -D THREE=51 -D FOUR=52 -D PLUS=61 -D MINUS=45 -D SCRLDWN=5 -D SCRLUP=4
else
MLX_DIR		= mlx_mac
IMLX		= -L$(MLX_DIR) -lmlx -framework OpenGL -framework appKit
DEFINES		= -D ESC=53 -D ONE=18 -D TWO=19 -D THREE=20 -D FOUR=21 -D PLUS=24 -D MINUS=27 -D SCRLDWN=4 -D SCRLUP=5
endif

MLX = $(MLX_DIR)/libmlx.a

#-----RULES-----#
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(ILIBFT) $(IMLX) $(DEFINES) -o $(NAME)

clean:
	$(RM) $(OBJS)
	@cd $(LIBFT_DIR) && $(MAKE) clean
	@cd $(MLX_DIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(MLX)

re: fclean all

.c.o:
	$(CC) $(CFLAGS) $(DEFINES) -c $< -o $@

$(MLX):
	@cd $(MLX_DIR) && $(MAKE)

$(LIBFT):
	@cd $(LIBFT_DIR) && $(MAKE)

$(BUILD):
	@cd UnitTests && cmake -S . -B build

test: $(LIBFT) $(BUILD)
	@cd UnitTests && cmake --build build && cd build && ctest --output-on-failure

cleantest:
	$(RM) $(BUILD)

retest: cleantest test

.PHONY: all clean fclean re test clean test retest
