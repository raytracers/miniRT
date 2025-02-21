/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:11:14 by gcorreia          #+#    #+#             */
/*   Updated: 2022/08/01 10:32:36 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 1;
	while (lst->next)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

//#include <stdio.h>
//
//int main()
//{
//  struct s_list   **ptr;
//  struct s_list   *head;
//  struct s_list   *first;
//  struct s_list   *second;
//  int				count;
//
//  ptr = &head;
//  head = ft_lstnew("original");
//  first = ft_lstnew("first");
//  second = ft_lstnew("second");
//  ft_lstadd_front(ptr, first);
//  ft_lstadd_front(ptr, second);
//  count = ft_lstsize(*ptr);
//  printf("%d\n", count);
//}
