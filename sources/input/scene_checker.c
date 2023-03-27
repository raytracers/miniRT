/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:07:32 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/27 21:31:44 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

int	scene_check(t_scene *scene)
{
	if (scene->camera == NULL)
	{
		ft_putstr_fd("ERROR: No camera data found\n", STDERR_FILENO);		
		return (1);
	}
	if (scene->light == NULL)
	{
		ft_putstr_fd("ERROR: No light data found\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}
