/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:41:16 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/12 20:44:03 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	log_msg(char *msg)
{
	ft_putstr_fd("[log]:\t", STDOUT_FILENO);
	ft_putendl_fd(msg, STDOUT_FILENO);
}
