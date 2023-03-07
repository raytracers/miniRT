/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:14:37 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/07 16:41:15 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	print_correct_usage(void)
{
	ft_putendl_fd("USAGE: ./miniRT <filename>.rt", STDERR_FILENO);
}

void	print_wrong_extension(void)
{
	ft_putendl_fd("ERROR: the current file is not a .rt file", STDERR_FILENO);
}

void	print_read_error(char *filename)
{
	ft_putstr_fd("ERROR: could not read file: ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putendl_fd(": permission denied", STDERR_FILENO);
}

void	print_no_file(char *filename)
{
	ft_putstr_fd("ERROR: file does not exist: ", STDERR_FILENO);
	ft_putendl_fd(filename, STDERR_FILENO);
}
