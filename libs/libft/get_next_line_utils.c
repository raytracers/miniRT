/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:41:42 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/27 22:15:15 by freemanc1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_clean_buffer(char **buffer)
{
	int	i;

	i = 0;
	while (i < 4096)
	{
		if (buffer[i] != NULL)
		{
			free(buffer[i]);
			buffer[i] = NULL;
		}
		i++;
	}	
	return (NULL);
}
