/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:57:34 by gcorreia          #+#    #+#             */
/*   Updated: 2022/06/08 14:39:04 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*new;

	new = (t_list *)malloc(sizeof(struct s_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

//#include <stdio.h>
//
//int main()
//{
//	char			str[] = "testing";
//	struct s_list	*head;
//	
//	head = ft_lstnew(str);
//	printf("%s\n", head->content);
//	if (head->next == NULL)
//		printf("OK\n");
//}
