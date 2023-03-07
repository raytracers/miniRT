/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:57 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/07 16:09:50 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <string.h>

int	check_argc(int argc)
{
	if ((argc - 1) != 1)
		return (0);
	return (1);
}

int	check_file_extension(char *filename)
{
	int		filename_len;

	filename_len = strlen(filename);
	if (filename_len < 4)
		return (0);
	if (filename[filename_len - 3] == '.' \
		&& filename[filename_len - 2] == 'r' \
		&& filename[filename_len - 1] == 't')
		return (1);
	return (0);
}

// o intuito desta função é que ela chame todas as outras funções de validação
int	validate_args(int argc, char **argv)
{
	if (!check_argc(argc))
	{
		print_correct_usage();
		return (0);
	}
	if (!check_file_extension(argv[1]))
	{
		print_wrong_extension();
		return (0);
	}
	return (1);
}
