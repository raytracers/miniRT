/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:57 by lfarias-          #+#    #+#             */
/*   Updated: 2023/02/13 17:56:27 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <string.h>

int	check_argc(int argc)
{
	if (argc != 1)
		return (1);
	return (0);
}

int check_file_extension(char *filename)
{
	int		filename_len;
	int		i;

	i = 0;
	filename_len = strlen(filename);
	if (filename_len < 4)
		return (1);
	if (filename[filename_len - 3] == '.' \
		&& filename[filename_len - 2] == 'r' \
		&& filename[filename_len - 1] == 't')
		return (0);
	return (1);
}
