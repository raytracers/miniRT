/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:49:59 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/20 14:19:22 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "types.h"

/* ************************* ALGEBRIC OPERATIONS **************************** */

double	quadratic_solver(double b, double c);

/* ************************************************************************** */

/* ************************** VECTOR OPERATIONS ***************************** */

double	dot_product(t_point a, t_point b);
t_point	vector_dif(t_point a, t_point b);
t_point	vector_sum(t_point a, t_point b);
t_point	vector_scalar(t_point v, double s);
t_point	normalize(t_point v);
t_point	cross_product(t_point a, t_point b);
t_point	transform_vector(t_point v, double *m[4]);

/* ************************************************************************** */

/* ************************** MATRIX OPERATIONS ***************************** */

double	**get_vtm(double **rtm, t_camera *c);
double	**get_rtm(t_camera *c);
void	transform_camera(t_camera *c, double **vtm, double **rtm);
void	transform_light(t_light *l, double **vtm);
void	transform_sphere(union u_object *o, double **vtm, double **rtm);
void	transform_cylinder(union u_object *o, double **vtm, double **rtm);
void	transform_plane(union u_object *o, double **vtm, double **rtm);

/* ************************************************************************** */

#endif
