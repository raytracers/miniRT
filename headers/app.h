/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:50:58 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/10 20:16:10 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# include "types.h"

/* *********************** FREE FUNCTIONS ***************************** */

void	destroy_scene(t_scene *scene, int scene_fd);
void	scene_close(int scene_fd);
#endif
