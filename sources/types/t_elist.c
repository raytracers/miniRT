/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_elist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:12:08 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/10 19:18:43 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

typedef int	(*t_init_function)(char **, union u_object *);

static t_elist	*elist_last(t_elist *lst);
static void		get_functions(t_init_function *functions);

t_elist	*elist_new(enum e_element type, char **content, int *op_code)
{
	t_init_function	init_fn[4];
	t_elist			*new_node;

	new_node = malloc(sizeof(t_elist));
	if (!new_node)
		return (NULL);
	get_functions(init_fn);
	new_node->type = type;
	*op_code = init_fn[type](content, &new_node->object);
	if (*op_code != 0)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

static void	get_functions(t_init_function *functions)
{
	functions[sphere] = init_sphere;
	functions[plane] = init_plane;
	functions[cylinder] = init_cylinder;
	functions[cone] = init_cylinder;
}

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
