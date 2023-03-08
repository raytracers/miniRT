/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digit_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:47:42 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/08 12:24:41 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_digit_str(char *str)
{
	if (!str || !(*str))
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str)
		return (0);
	return (1);
}
