/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:55:27 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/20 09:48:02 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "types.h"

t_intersection	sphere_intersection(t_ray ray, union u_object object);
void			transform_scene(t_scene *scene);
void			free_vtm(double **vtm);
void			free_matrix(double **vtm);
void			transform_camera(t_camera *c, double **vtm, double **rtm);

#endif
