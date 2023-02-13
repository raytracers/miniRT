/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:41:10 by gcorreia          #+#    #+#             */
/*   Updated: 2022/09/12 11:54:24 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(const char *str)
{
	int	sign;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	return (sign);
}

static double	ft_pow(double nbr, int power)
{
	double	result;

	result = nbr;
	if (power == 0)
		result = 1;
	while (power > 1)
	{
		result *= nbr;
		power--;
	}
	return (result);
}

static const char	*move_to_decimal(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

double	ft_atof(const char *str)
{
	double	result;
	double	decimal;
	int		i;
	int		sign;

	sign = get_sign(str);
	result = ft_atoi(str);
	str = move_to_decimal(str);
	decimal = 0;
	if (*(str++) == '.')
	{
		i = 1;
		while (*str >= '0' && *str <= '9')
		{
			decimal += (*str - '0') / ft_pow(10, i);
			str++;
			i++;
		}
	}
	return (result + (sign * decimal));
}

//#include <stdlib.h>
//#include <stdio.h>
//int main()
//{
//	double	result;
//	double	ft_result;
//
//	result = atof("10.123456789");
//	ft_result = ft_atof("10.123456789");
//	printf("atof = %.10f\n", result);
//	printf("ft_atof = %.10f\n\n", ft_result);
//	
//	result = atof("0.0");
//	ft_result = ft_atof("0.0");
//	printf("atof = %.10f\n", result);
//	printf("ft_atof = %.10f\n\n", ft_result);
//}
