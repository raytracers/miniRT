/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:46:27 by gcorreia          #+#    #+#             */
/*   Updated: 2022/08/01 10:37:52 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	struct s_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

//#include <stdio.h>
//
//int main()
//{
//  struct s_list   **ptr;
//  struct s_list   *head;
//  struct s_list   *first;
//  struct s_list   *second;
//  struct s_list   *i;
//
//  ptr = &head;
//  head = ft_lstnew("original");
//  first = ft_lstnew("first");
//  second = ft_lstnew("second");
//  ft_lstadd_back(ptr, first);
//  ft_lstadd_back(ptr, second);
//  i = *ptr;
//  while(i->next != NULL)
//  {
//      printf("%s\n", i->content);
//      i = i->next;
//  }
//  printf("%s\n", i->content);
//}
