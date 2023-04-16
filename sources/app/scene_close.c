/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:58:28 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/10 20:30:42 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <errno.h>
#include <string.h>

void	scene_close(int scene_fd)
{
	if (close(scene_fd) == -1)
	{
		ft_putstr_fd("ERROR: ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
	}
}
