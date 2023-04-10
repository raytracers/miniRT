/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:14:37 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/10 19:09:20 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <errno.h>
#include <string.h>

char	*get_error_msg(int error_code)
{
	char	*error_msg[12];

	error_msg[err_usage] = "USAGE: ./miniRT <filename>.rt";
	error_msg[err_file_type] = "the current file is not a .rt file";
	error_msg[err_file_fmt] = "the file formatting is invalid";
	error_msg[err_file_perm] = "could not read file: permission denied";
	error_msg[err_file_not_found] = "file not found";
	error_msg[err_obj_attr_fmt] = "invalid format for object's attribute";
	error_msg[err_obj_attr_value] = "invalid value for object's attribute";
	error_msg[err_obj_attr_miss] = "wrong attr size in object declaration";
	error_msg[err_obj_dup] = "multiple unique objects [light, camera, a_light]";
	error_msg[err_obj_invalid] = "invalid object";
	return (error_msg[error_code]);
}

void	print_error_msg(int err_code)
{
	char	*msg;

	msg = get_error_msg(err_code);
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
}

void	print_file_error(int err_code, char *filename)
{
	print_error_msg(err_code);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(filename, STDERR_FILENO);
}

void	print_scene_error(int err_code, int line_number)
{
	char	*nbr_str;

	nbr_str = ft_itoa(line_number);
	print_error_msg(err_code);
	ft_putstr_fd(": line ", STDERR_FILENO);
	ft_putendl_fd(nbr_str, STDERR_FILENO);
	free(nbr_str);
}

void	print_error(char *filename)
{
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
}
