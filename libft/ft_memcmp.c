/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:32:15 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/03 16:37:21 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pointer_s1;
	unsigned char	*pointer_s2;

	pointer_s1 = (unsigned char *)s1;
	pointer_s2 = (unsigned char *)s2;
	i = 0;
	while ((i < n))
	{
		if (pointer_s1[i] != pointer_s2[i])
			return (pointer_s1[i] - pointer_s2[i]);
		i++;
	}
	return (0);
}
