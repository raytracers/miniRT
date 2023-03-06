/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:26:53 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/06 16:31:57 by gcorreia         ###   ########.fr       */
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
	cylinder,
	nae
};

typedef struct s_a_light
{
	double	ratio;
	int		color;
}	t_a_light;

typedef struct s_camera
{
	t_point	origin;
	t_point	orientation;
	int		fov;
}	t_camera;

typedef struct s_light
{
	t_point	origin;
	double	brightness;
}	t_light;

typedef struct s_sphere
{
	t_point	origin;
	double	diameter;
	int		color;
}	t_sphere;

typedef struct s_plane
{
	t_point	origin;
	t_point	normal;
	int		color;
}	t_plane;

typedef struct s_cylinder
{
	t_point	origin;
	t_point	orientation;
	double	diameter;
	double	height;
	int		color;
}	t_cylinder;

union u_element
{
	t_a_light	ambient_light;
	t_camera	camera;
	t_light		light;
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
};

typedef struct s_elist
{
	enum e_element		type;
	union u_element		element;
	struct s_elist	*next;

}	t_elist;

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
