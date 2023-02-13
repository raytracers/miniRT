/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:17:48 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/04 11:27:32 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	destlen;

	destlen = ft_strlen(dest);
	if (destlen > destsize)
		return (destsize + ft_strlen(src));
	i = 0;
	while ((i + destlen + 1 < destsize) && src[i] != '\0')
	{
		dest[destlen + i] = src[i];
		i++;
	}
	if (destsize > 0)
		dest[destlen + i] = '\0';
	return (destlen + ft_strlen(src));
}
