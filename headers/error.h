/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:37:06 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/10 19:02:45 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum e_error_codes{
	naerr,
	err_usage,
	err_file_type,
	err_file_fmt,
	err_file_perm,
	err_file_not_found,
	err_obj_attr_value,
	err_obj_attr_fmt,
	err_obj_attr_miss,
	err_obj_dup,
	err_obj_invalid
};

char			*get_error_msg(int error_code);
void			print_error_msg(int err_code);
void			print_file_error(int err_code, char *filename);
void			print_scene_error(int err_code, int line_number);
void			print_error(char *filename);

#endif
