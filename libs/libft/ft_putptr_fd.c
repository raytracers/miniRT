/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:38:21 by gcorreia          #+#    #+#             */
/*   Updated: 2022/07/01 19:57:17 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long int	ft_get_magnitude(unsigned long int p)
{
	unsigned long int	magnitude;

	magnitude = 1;
	while (p / magnitude >= 16 && magnitude < magnitude * 16)
		magnitude *= 16;
	return (magnitude);
}

int	ft_putptr_fd(unsigned long int p, int fd)
{
	unsigned long int	magnitude;
	int					count;

	magnitude = ft_get_magnitude(p);
	count = 0;
	count += ft_putstr_fd("0x", 1);
	while (magnitude >= 1)
	{
		if (p / magnitude < 10)
			count += ft_putchar_fd(p / magnitude + '0', fd);
		else
			count += ft_putchar_fd(p / magnitude % 10 + 'a', fd);
		p = p - (p / magnitude) * magnitude;
		magnitude /= 16;
	}
	return (count);
}
