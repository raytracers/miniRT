/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:13:55 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/03 15:30:20 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, size);
	ft_strlcat(str, s2, size);
	return (str);
}
