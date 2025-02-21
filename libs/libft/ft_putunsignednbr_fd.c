/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:48:37 by gcorreia          #+#    #+#             */
/*   Updated: 2022/07/01 15:10:33 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putunsignednbr_fd(unsigned int n, int fd)
{
	int				printcount;
	unsigned int	magnitude;

	printcount = 0;
	magnitude = 1;
	while ((n / magnitude) >= 10 && magnitude < magnitude * 10)
		magnitude *= 10;
	while (magnitude >= 1)
	{
		printcount += ft_putchar_fd((n / magnitude) + '0', fd);
		n = n - (n / magnitude) * magnitude;
		magnitude /= 10;
	}
	return (printcount);
}
