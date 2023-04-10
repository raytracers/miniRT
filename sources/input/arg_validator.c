/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:58:57 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/10 16:36:50 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	check_argc(int argc)
{
	if ((argc) != 1)
		return (0);
	return (1);
}

int	check_file_extension(char *filename)
{
	int		filename_len;

	filename_len = ft_strlen(filename);
	if (filename_len < 4)
		return (0);
	if (filename[filename_len - 3] == '.' \
		&& filename[filename_len - 2] == 'r' \
		&& filename[filename_len - 1] == 't')
		return (1);
	return (0);
}

int	validate_args(int argc, char **argv)
{
	if (!check_argc(argc - 1))
	{
		ft_putendl_fd(get_error_msg(err_usage), STDERR_FILENO);
		return (0);
	}
	if (!check_file_extension(argv[1]))
	{
		print_file_error(err_file_type, argv[1]);
		return (0);
	}
	return (1);
}
