/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:58:15 by gcorreia          #+#    #+#             */
/*   Updated: 2022/08/01 10:32:19 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*iterator;

	head = NULL;
	while (lst)
	{
		iterator = ft_lstnew(f(lst->content));
		if (!iterator)
		{
			ft_lstclear(&iterator, del);
			return (NULL);
		}
		ft_lstadd_back(&head, iterator);
		lst = lst->next;
	}
	return (head);
}
