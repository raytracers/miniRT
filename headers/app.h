/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:50:58 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/16 12:10:15 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# include "types.h"

/* *********************** FREE FUNCTIONS ***************************** */

void	destroy_scene(t_scene *scene);

/* *********************** LOG FUNCTIONS ***************************** */
void	log_msg(char *msg);
void	log_render_time(long time);
void	log_scene(t_scene *scene);
long	get_currtime_ms(void);
#endif
