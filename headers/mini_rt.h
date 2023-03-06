/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:26:53 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/06 18:18:15 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "types.h"
# include "../libft/libft.h"
# include "mlx.h"
# include "mlx_functions.h"
# include <stdlib.h>

/* *********************** SPACE RELATED TYPES ****************************** */

int				check_argc(int argc);
int				check_file_extension(char *filename);
int				validate_args(int argc, char **argv);
enum e_element	get_element(char *elem);

/* ************************************************************************** */

// scene
int				scene_open(char *filename);
#endif
