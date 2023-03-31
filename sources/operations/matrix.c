/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:25:47 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/29 17:41:14 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

double	**malloc_matrix(void)
{
	double	**m;
	int		i;

	m = ft_calloc(4, sizeof(double *));
	if (!m)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		m[i] = ft_calloc(4, sizeof(double));
		if (!m[i])
		{
			free_matrix(m);
			return (NULL);
		}
		++i;
	}
	m[3] = NULL;
	return (m);
}

void	free_matrix(double **m)
{
	double	**p;

	if (!m)
		return ;
	p = m;
	while (*p)
	{
		free(*p);
		++p;
	}
	free(m);
}
