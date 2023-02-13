/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:34:54 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/01 09:24:14 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*pointer_dest;
	char	*pointer_src;

	pointer_dest = (char *)dest;
	pointer_src = (char *)src;
	i = 0;
	while (i < n)
	{
		*(pointer_dest + i) = *(pointer_src + i);
		i++;
	}
	return (dest);
}
