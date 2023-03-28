/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:55:27 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/28 00:46:42 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "types.h"

t_intersection	get_intersection(t_ray ray, t_elist *e);
t_intersection	sphere_intersection(t_ray ray, union u_object object);
t_intersection	plane_intersection(t_ray ray, union u_object object);
int				transform_scene(t_scene *scene);
int				get_px_color(t_intersection i, t_scene *s);
void			free_vtm(double **vtm);
void			free_matrix(double **vtm);
void			render_scene(t_scene *scene, t_window *win);

#endif
