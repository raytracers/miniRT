/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:20:54 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/10 18:59:22 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "types.h"

/* *********************** VALIDATION FUNCTIONS ***************************** */

int				check_argc(int argc);
int				check_file_extension(char *filename);
int				validate_args(int argc, char **argv);
int				scene_check(t_scene *scene);

/* ************************************************************************** */

/* ********************* INTERPRETATION FUNCTIONS *************************** */

int				scene_open(char *filename);
int				scene_load(int scene_fd, t_scene *scene);
enum e_element	get_element(char *elem, int ln);
int				get_color(char *rgb);
int				get_point(char *str, t_point *point);
int				is_normalized(t_point vector);

/* ************************************************************************** */

#endif
