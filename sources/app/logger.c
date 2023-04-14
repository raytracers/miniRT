/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:41:16 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/14 18:25:59 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	log_msg(char *msg)
{
	ft_putstr_fd("[log]:\t", STDOUT_FILENO);
	ft_putendl_fd(msg, STDOUT_FILENO);
}

void	log_render_time(long time)
{
	long	seconds;

	seconds = time / 1000;
	ft_putstr_fd("[log]:\tRENDER READY - time elapsed: ", STDOUT_FILENO);
	ft_putnbr_fd(seconds, STDOUT_FILENO);
	ft_putstr_fd(" seconds!\n", STDOUT_FILENO);
}
