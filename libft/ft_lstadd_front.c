/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:39:56 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/08 17:15:54 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

//#include <stdio.h>
//
//int main()
//{
//	struct s_list	**ptr;
//	struct s_list	*head;
//	struct s_list	*first;
//	struct s_list	*second;
//	struct s_list	*i;
//
//	ptr = &head;
//	head = ft_lstnew("original");
//	first = ft_lstnew("first");
//	second = ft_lstnew("second");
//	ft_lstadd_front(ptr, first);
//	ft_lstadd_front(ptr, second);
//	i = *ptr;
//	while(i->next != NULL)
//	{
//		printf("%s\n", i->content);
//		i = i->next;
//	}
//	printf("%s\n", i->content);
//}
