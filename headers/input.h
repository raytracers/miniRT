/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:20:54 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/09 18:16:50 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "types.h"

/* *********************** VALIDATION FUNCTIONS ***************************** */

int				check_argc(int argc);
int				check_file_extension(char *filename);
int				validate_args(int argc, char **argv);

/* ************************************************************************** */

/* ********************* INTERPRETATION FUNCTIONS *************************** */

int				scene_open(char *filename);
enum e_element	get_element(char *elem);
int				get_color(char *rgb);
int				get_point(char *str, t_point *point);
int				init_sphere(char **attributes, union u_element *sphere);
int				init_camera(char **attributes, union u_element *camera);
int				init_plane(char **attributes, union u_element *element);
int				is_normalized(t_point vector);

/* ************************************************************************** */

#endif
