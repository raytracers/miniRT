/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:55:35 by gcorreia          #+#    #+#             */
/*   Updated: 2022/07/01 15:05:42 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_negative(int n)
{
	if (n >= 0)
		return (0);
	else
		return (1);
}

static void	ft_fill_string(char *str, int n)
{
	int		i;
	int		n_is_negative;

	n_is_negative = ft_is_negative(n);
	i = 0;
	if (n == 0)
		str[i++] = '0';
	else
	{
		while (n != 0)
		{
			if (n_is_negative)
				str[i++] = '0' - (n % 10);
			else
				str[i++] = '0' + (n % 10);
			n /= 10;
		}
		if (n_is_negative)
			str[i++] = '-';
	}
	str[i] = '\0';
	ft_invert_str(str);
}

static int	ft_count_digits(int n)
{
	int	base;
	int	digits;

	digits = 10;
	base = 1000000000;
	if (n < 0)
		digits++;
	while (n / base == 0 && base > 1)
	{
		base /= 10;
		digits--;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_count_digits(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	else
		ft_fill_string(str, n);
	return (str);
}
