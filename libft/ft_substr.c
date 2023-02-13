/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:41:00 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/04 10:24:42 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	char	*index;

	i = 0;
	if (start > ft_strlen(s))
	{
		substr = malloc(1);
		substr[i] = '\0';
		return (substr);
	}
	index = (char *)(s + start);
	substr = malloc(ft_strlen(index) + 1);
	if (substr == NULL)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
