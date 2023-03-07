/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:14:37 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/07 16:04:44 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	print_correct_usage(void)
{
	ft_putendl_fd("USAGE: ./miniRT <filename>.rt", 2);
}

void	print_wrong_extension(void)
{
	ft_putendl_fd("ERROR: the current file is not a .rt file", 2);
}
