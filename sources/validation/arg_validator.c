/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:57 by lfarias-          #+#    #+#             */
/*   Updated: 2023/02/13 18:17:20 by gcorreia         ###   ########.fr       */
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

// o intuito desta função é que ela chame todas as outras funções de validação
int	validate_args(int argc, char **argv)
{
	if (!check_argc(argc) || !check_file_extension(argv[1]))
		return (1);
	return (0);
}
