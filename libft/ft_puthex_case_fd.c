/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_case_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:54:04 by gcorreia          #+#    #+#             */
/*   Updated: 2022/07/01 19:20:07 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_getcasing(char c)
{
	if (c >= 'A' && c <= 'Z')
		return ('A');
	else
		return ('a');
}

static unsigned int	ft_get_magnitude(unsigned int n)
{
	unsigned int	magnitude;

	magnitude = 1;
	while (n / magnitude >= 16 && magnitude < magnitude * 16)
		magnitude *= 16;
	return (magnitude);
}

int	ft_puthex_case_fd(unsigned int n, char c, int fd)
{
	unsigned int	magnitude;
	int				count;

	magnitude = ft_get_magnitude(n);
	c = ft_getcasing(c);
	count = 0;
	while (magnitude >= 1)
	{
		if (n / magnitude < 10)
			count += ft_putchar_fd(n / magnitude + '0', fd);
		else
			count += ft_putchar_fd((n / magnitude % 10) + c, fd);
		n = n - (n / magnitude) * magnitude;
		magnitude /= 16;
	}
	return (count);
}
