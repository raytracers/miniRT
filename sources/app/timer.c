/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:55:53 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/14 18:07:21 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <sys/time.h>

long	get_currtime_ms(void)
{
	struct timeval	current_time;
	long			ctime;

	gettimeofday(&current_time, NULL);
	ctime = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (ctime);
}
