/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:48:37 by gcorreia          #+#    #+#             */
/*   Updated: 2022/07/01 19:17:44 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_modulus(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static int	ft_get_magnitude(int n)
{
	int	magnitude;

	magnitude = 1;
	if (n == -2147483648)
		magnitude *= 10;
	while (ft_modulus(n / magnitude) >= 10 && magnitude < magnitude * 10)
		magnitude *= 10;
	return (magnitude);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	magnitude;
	int	count;

	count = 0;
	magnitude = ft_get_magnitude(n);
	if (n < 0)
		count += ft_putchar_fd('-', fd);
	while (magnitude >= 1)
	{
		if (n / magnitude < 10)
			count += ft_putchar_fd(ft_modulus(n / magnitude) + '0', fd);
		else
			count += ft_putchar_fd((ft_modulus(n / magnitude) % 10) + 'A', fd);
		if (n > 0)
			n = n - (n / magnitude) * magnitude;
		else
			n = n + ft_modulus(n / magnitude) * magnitude;
		magnitude /= 10;
	}
	return (count);
}
