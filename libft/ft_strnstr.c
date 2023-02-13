/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:29:22 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/03 18:43:35 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*ptr;
	int		size;

	ptr = (char *)big;
	size = ft_strlen(little);
	if (size == 0)
		return (ptr);
	i = 0;
	while (i + size <= len && big[i] != '\0')
	{
		if (ft_strncmp(ptr + i, little, ft_strlen(little)) == 0)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
