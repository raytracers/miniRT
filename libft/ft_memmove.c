/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:36:40 by gcorreia          #+#    #+#             */
/*   Updated: 2022/05/17 12:42:29 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*pointer_dest;
	char	*pointer_src;

	pointer_dest = (char *)dest;
	pointer_src = (char *)src;
	i = 0;
	if (pointer_dest > pointer_src)
		while (n-- > 0)
			pointer_dest[n] = pointer_src[n];
	else
	{
		while (i < n)
		{
			pointer_dest[i] = pointer_src[i];
			i++;
		}
	}
	return (dest);
}
