/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_elist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:12:08 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/09 16:41:46 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/types.h"
#include <stdlib.h>

static t_elist	*elist_last(t_elist *lst);

void	free_elist(t_elist **head)
{
	t_elist	*tmp;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		free(*head);
		*head = tmp;
	}
}

void	elist_addback(t_elist **lst, t_elist *n)
{
	t_elist	*last;

	if (!lst || !n)
		return ;
	last = elist_last(*lst);
	if (!last)
		*lst = n;
	else
		last->next = n;
}

static t_elist	*elist_last(t_elist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
