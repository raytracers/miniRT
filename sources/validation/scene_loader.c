/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 02:16:42 by lfarias-          #+#    #+#             */
/*   Updated: 2023/02/13 18:19:15 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <unistd.h>
#include <fcntl.h>

int	scene_open(char *filename)
{
	int	scene_fd;

	scene_fd = open(filename, O_RDONLY);
	return (scene_fd);
}
