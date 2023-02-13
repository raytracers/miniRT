/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:34:53 by gcorreia          #+#    #+#             */
/*   Updated: 2022/07/05 13:52:47 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_argument(const char *index, va_list *args)
{
	if (index[1] == '\0')
		return (0);
	else if (index[1] == 'c')
		return (ft_putchar_fd((char)va_arg(*args, int), 1));
	else if (index[1] == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	else if (index[1] == 'p')
		return (ft_putptr_fd(va_arg(*args, unsigned long int), 1));
	else if (index[1] == 'd' || index[1] == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	else if (index[1] == 'u')
		return (ft_putunsignednbr_fd(va_arg(*args, unsigned int), 1));
	else if (index[1] == 'x')
		return (ft_puthex_case_fd(va_arg(*args, unsigned int), 'a', 1));
	else if (index[1] == 'X')
		return (ft_puthex_case_fd(va_arg(*args, unsigned int), 'A', 1));
	else if (index[1] == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (ft_putchar_fd(index[1], 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;
	int		printcount;
	int		len;

	len = ft_strlen(str);
	va_start(args, str);
	printcount = 0;
	index = 0;
	while (index < len)
	{
		if (str[index] != '%')
			printcount += ft_putchar_fd(str[index], 1);
		else
		{
			printcount += ft_handle_argument(str + index, &args);
			index++;
		}
		index++;
	}
	va_end(args);
	return (printcount);
}
