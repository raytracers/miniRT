/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:14:37 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/07 15:53:42 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	print_correct_usage(void)
{
	ft_putendl_fd("USAGE:", 2);
	ft_putendl_fd("  ./miniRT <filename>.rt", 2);
}
