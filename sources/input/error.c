/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:14:37 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/14 13:27:15 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <errno.h>
#include <string.h>

void	print_correct_usage(void)
{
	ft_putendl_fd("USAGE: ./miniRT <filename>.rt", STDERR_FILENO);
}

void	print_invalid_file(void)
{
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	ft_putendl_fd("the current filename is not a .rt file", STDERR_FILENO);
}

void	print_read_error(char *filename)
{
	ft_putstr_fd("ERROR: could not read file: ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putendl_fd(": permission denied", STDERR_FILENO);
}

void	print_no_file(char *filename)
{
	ft_putstr_fd("ERROR: file not found: ", STDERR_FILENO);
	ft_putendl_fd(filename, STDERR_FILENO);
}

void	print_error(char *filename)
{
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
}
