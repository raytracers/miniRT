/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:08:22 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/07 15:17:53 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_arraylen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		++i;
	return (i);
}