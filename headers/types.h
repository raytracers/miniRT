/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:26:53 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/10 11:30:25 by gcorreia         ###   ########.fr       */
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

typedef struct s_ray
{
	t_point	origin;
	t_point	orientation;
}	t_ray;

enum	e_element
{
	sphere,
	plane,
	cylinder,
	ambient_light,
	camera,
	light,
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
	struct s_elist		*next;

}	t_elist;

typedef struct s_scene
{
	t_light			*light;
	t_a_light		*a_light;
	t_camera		*camera;
	t_elist			*elements;
	struct s_scene	*next;

}	t_scene;

void	elist_addback(t_elist **lst, t_elist *n);
void	free_elist(t_elist **head);
t_elist	*elist_new(enum e_element type, char **content);
int		init_sphere(char **attributes, union u_element *sphere);
int		init_cylinder(char **attributes, union u_element *cylinder);
int		init_camera(char **attributes, union u_element *camera);
int		init_plane(char **attributes, union u_element *element);

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
