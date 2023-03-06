/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:26:53 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/06 11:46:08 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/* *********************** SPACE RELATED TYPES ****************************** */

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_vector
{
	t_point	origin;
	t_point	orientation;
}	t_vector;

/* ************************************************************************** */

/* *********************** SCENE RELATED TYPES ****************************** */

enum	e_element
{
	ambient_light,
	camera,
	light,
	sphere,
	plane,
	cylinder
};

/* ************************************************************************** */


/* ************************ MLX RELATED TYPES ******************************* */

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_window
{
	t_img	image;
	t_vars	vars;
	int		size;
}				t_window;

/* ************************************************************************** */

#endif
