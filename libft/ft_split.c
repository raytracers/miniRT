/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:41:12 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/07 10:06:06 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_initialize_string(char const *s, char c, int index, char *str)
{
	int	i;

	i = 0;
	while (s[index] != c && s[index] != '\0')
	{
		str[i] = s[index++];
		i++;
	}
	str[i] = '\0';
}

static char	*ft_allocate_string(char const *s, char c, int index)
{
	int		size;
	char	*str;

	size = 0;
	while (s[index] != c && s[index] != '\0')
	{
		size++;
		index++;
	}
	str = malloc(size + 1);
	return (str);
}

static void	ft_initialize_array(char **array, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			array[j] = ft_allocate_string(s, c, i);
			ft_initialize_string(s, c, i, array[j]);
			i += ft_strlen(array[j]) - 1;
			j++;
		}
		i++;
	}
	array[j] = NULL;
}

static int	ft_count_strings(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (c == '\0')
		return (2);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		nelem;
	char	**array;

	nelem = ft_count_strings(s, c);
	array = ft_calloc(nelem, sizeof(char *));
	if (array == NULL)
		return (NULL);
	ft_initialize_array(array, s, c);
	return (array);
}
