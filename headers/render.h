/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:55:27 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/29 18:45:57 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "types.h"

t_intersection	get_intersection(t_ray ray, t_elist *e);
t_intersection	sphere_intersection(t_ray ray, union u_object object);
int				transform_scene(t_scene *scene);
int				get_px_color(t_intersection i, t_scene *s);
void			transform_objects(t_elist *lst, double **vtm, double **rtm);
void			free_vtm(double **vtm);
void			render_scene(t_scene *scene, t_window *win);
void			interactive_render(t_scene *scene, t_window *win);
void			move_foreward(t_scene *s);
void			move_back(t_scene *s);
void			move_left(t_scene *s);
void			move_right(t_scene *s);
void			turn_up(t_scene *s);
void			turn_down(t_scene *s);
void			turn_left(t_scene *s);
void			turn_right(t_scene *s);
void			spin_left(t_scene *s);
void			spin_right(t_scene *s);

#endif
