/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:55:27 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/09 14:06:07 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "types.h"

/* **************************** Render Functions **************************** */

void			render_scene(t_scene *scene, t_window *win);
void			interactive_render(t_scene *scene, t_window *win);

/* ************************************************************************** */

/* ************************ Intersection Functions ************************** */

t_intersection	get_intersection(t_ray ray, t_elist *e);
t_intersection	sphere_intersection(t_ray ray, union u_object object);
t_intersection	plane_intersection(t_ray ray, union u_object object);
t_intersection	cylinder_intersection(t_ray ray, union u_object object);
t_intersection	cone_intersection(t_ray ray, union u_object object);

/* ************************************************************************** */

/* ********************** Transformation Functions ************************** */

int				transform_scene(t_scene *scene);
void			transform_objects(t_elist *lst, double **vtm, double **rtm);
void			move_foreward(t_scene *s);
void			move_back(t_scene *s);
void			move_left(t_scene *s);
void			move_right(t_scene *s);
void			move_up(t_scene *s);
void			move_down(t_scene *s);
void			turn_up(t_scene *s);
void			turn_down(t_scene *s);
void			turn_left(t_scene *s);
void			turn_right(t_scene *s);
void			spin_left(t_scene *s);
void			spin_right(t_scene *s);

/* ************************************************************************** */

/* ************************** Color Functions ******************************* */

int				get_px_color(t_intersection i, t_ray view_d, t_scene *s);
int				compute_diffuse(t_scene *s, t_ray ld, t_intersection i);
int				compute_ambient(t_intersection intersec, t_a_light *light);
int				compute_specular(t_point v, t_point l, t_point n,
					t_light *light);

/* ************************************************************************** */

#endif
