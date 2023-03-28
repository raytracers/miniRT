/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:37:06 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/14 13:26:47 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void			print_correct_usage(void);
void			print_invalid_file(void);
void			print_read_error(char *filename);
void			print_no_file(char *filename);
void			print_error(char *filename);

#endif
