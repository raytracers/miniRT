/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:20:00 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/03 19:19:03 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	while ((i + 1 < destsize) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (destsize > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
