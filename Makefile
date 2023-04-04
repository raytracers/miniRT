# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:25:00 by lfarias-          #+#    #+#              #
#    Updated: 2023/04/04 14:45:26 by gcorreia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----PROJECT VARIABLES-----#
NAME	=	miniRT

BUILD	= UnitTests/build

CC		= cc

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -O3

#-----C FILES-----#

INPUT = $(addprefix input/,	\
	arg_validator.c					\
	scene_open.c					\
	scene_loader.c 					\
	scene_checker.c					\
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
	init_light.c 			\
	init_ambient_light.c 	\
	new_point.c			 	\
	get_ray.c			 	\
)

RENDER = $(addprefix render/,	\
	transform_scene.c			\
	sphere_intersection.c		\
	plane_intersection.c 		\
	render_scene.c				\
	get_px_color.c				\
	compute_diffuse.c			\
	compute_ambient.c			\
	get_intersection.c			\
	interactive_render.c		\
	move_scene.c				\
	rotate_scene.c				\
	interactive_z_axis.c		\
)

OPERATIONS = $(addprefix operations/,	\
	quadratic_solver.c					\
	vector_operations.c					\
	vector_operations2.c				\
	cross_product.c						\
	transform_vector.c					\
	transform_elements.c				\
	vtm.c								\
	rtm.c								\
	matrix.c							\
	get_distance.c						\
)

APP = $(addprefix app/,	\
	destroy_scene.c		\
)

MY_MLX		= $(addprefix mlx/,	\
	utils.c						\
	initialization.c			\
	events.c					\
)

MAIN 		= main.c

SRCS 		= $(addprefix sources/,	\
	$(MAIN)							\
	$(APP)							\
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
DEFINES		= -D ESC=53 -D KEY_I=34 -D KEY_R=15 -D KEY_W=13 -D KEY_A=0	\
			  -D KEY_S=1 -D KEY_D=2 -D KEY_LEFT=123 -D KEY_RIGHT=124	\
			  -D KEY_DOWN=125 -D KEY_UP=126 -D KEY_HOOKR=33				\
			  -D KEY_HOOKL=30 -D KEY_CTRL=256 -D KEY_SPACE=49
else
MLX_DIR		= mlx_mac
IMLX		= -L$(MLX_DIR) -lmlx -framework OpenGL -framework appKit
DEFINES		= -D ESC=53 -D KEY_I=34 -D KEY_R=15 -D KEY_W=13 -D KEY_A=0	\
			  -D KEY_S=1 -D KEY_D=2 -D KEY_LEFT=123 -D KEY_RIGHT=124	\
			  -D KEY_DOWN=125 -D KEY_UP=126 -D KEY_HOOKR=33				\
			  -D KEY_HOOKL=30 -D KEY_CTRL=256 -D KEY_SPACE=49
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

run1: $(NAME)
	./$(NAME) ./scenes/scene.rt

.PHONY: all clean fclean re test clean test retest
