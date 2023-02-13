/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:32:36 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/09 13:48:16 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	struct s_list	*ptr;

	ptr = *lst;
	while (1)
	{
		del(ptr->content);
		ptr = ptr->next;
		free(*lst);
		if (ptr == NULL)
			break ;
		*lst = ptr;
	}
	*lst = NULL;
}
