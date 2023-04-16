/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:41:16 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/16 11:21:43 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	count_elements(t_scene *scene, int elements_qty[7]);

void	log_msg(char *msg)
{
	ft_putstr_fd("[log]:\t", STDOUT_FILENO);
	ft_putendl_fd(msg, STDOUT_FILENO);
}

void	log_render_time(long time)
{
	long	seconds;

	seconds = time / 1000;
	ft_putstr_fd("[log]:\tRENDER READY - time elapsed: ", STDOUT_FILENO);
	ft_putnbr_fd(seconds, STDOUT_FILENO);
	ft_putstr_fd(" seconds!\n", STDOUT_FILENO);
}

void	log_scene(t_scene *scene)
{
	int		elements_qty[7];
	char	*field_names[4];
	int		i;

	count_elements(scene, elements_qty);
	ft_putstr_fd("[log]:\tsuccessfully loaded scene with:", STDOUT_FILENO);
	field_names[0] = "\n\tSphere(s): ";
	field_names[1] = "\n\tPlane(s): ";
	field_names[2] = "\n\tCylinder(s): ";
	field_names[3] = "\n\tCones(s): ";
	i = -1;
	while (++i < 4)
	{
		if(elements_qty[i] != 0)
		{
			ft_putstr_fd(field_names[i], STDOUT_FILENO);
			ft_putnbr_fd(elements_qty[i], STDOUT_FILENO);
		}
	}
	if (scene->a_light != NULL)
		ft_putstr_fd("\n\tambient light: yes", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void	count_elements(t_scene *scene, int elements_qty[7])
{
	int			i;
	t_elist		*element;

	i = -1;
	while (++i < 7)
		elements_qty[i] = 0;
	i = 0;
	element = scene->elements;
	while (element)
	{
		elements_qty[element->type] += 1;
		element = element->next;
	}
}
