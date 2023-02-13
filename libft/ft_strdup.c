/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:08:11 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/06 14:18:02 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;
	int		size;	

	size = ft_strlen(str) + 1;
	ptr = malloc(size);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}
