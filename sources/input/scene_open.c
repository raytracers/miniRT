/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 02:16:42 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/12 20:48:01 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <errno.h>
#include <fcntl.h>

int	scene_open(char *filename)
{
	int	scene_fd;

	log_msg("opening the .rt file");
	scene_fd = open(filename, O_WRONLY);
	if (scene_fd < 0 && errno == EISDIR)
	{
		print_invalid_file();
		return (scene_fd);
	}
	close(scene_fd);
	scene_fd = open(filename, O_RDONLY);
	if (scene_fd >= 0)
		return (scene_fd);
	else if (errno == EPERM || errno == EACCES)
		print_read_error(filename);
	else if (errno == ENOENT)
		print_no_file(filename);
	else
		print_error(filename);
	return (scene_fd);
}
