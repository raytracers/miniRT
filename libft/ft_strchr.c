/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:32:37 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/03 17:00:01 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (char)c)
			return (i + ptr);
		i++;
	}
	if (ptr[i] == c)
		return (i + ptr);
	else
		return (0);
}
