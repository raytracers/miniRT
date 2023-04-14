/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:50:58 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/14 18:14:40 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# include "types.h"

/* *********************** FREE FUNCTIONS ***************************** */

void	destroy_scene(t_scene *scene);
void	log_msg(char *msg);
void	log_render_time(long time);
long	get_currtime_ms(void);
#endif
