/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:26:49 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/08 17:41:16 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

//#include <stdio.h>
// 
//int main()
//{
//  struct s_list   **ptr;
//  struct s_list   *head;
//  struct s_list   *first;
//  struct s_list   *second;
//  struct s_list   *last;
//
//  ptr = &head;
//  head = ft_lstnew("original");
//  first = ft_lstnew("first");
//  second = ft_lstnew("second");
//  ft_lstadd_front(ptr, first);
//  ft_lstadd_front(ptr, second);
//
//  last = ft_lstlast(*ptr);
//  printf("%s\n", last->content);
//}
