/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:00:48 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/20 14:20:07 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

typedef void	(*t_transform)(union u_object *, double **, double **);

static void	transform_objects(t_elist *lst, double **vtm, double **rtm);

int	transform_scene(t_scene *scene)
{
	double	**vtm;
	double	**rtm;

	rtm = get_rtm(scene->camera);
	if (!rtm)
		return (1);
	vtm = get_vtm(rtm, scene->camera);
	if (!vtm)
	{
		free_matrix(rtm);
		return (1);
	}
	transform_camera(scene->camera, vtm, rtm);
	transform_light(scene->light, vtm);
	transform_objects(scene->elements, vtm, rtm);
	free_matrix(rtm);
	free_matrix(vtm);
	return (0);
}

static void	transform_objects(t_elist *lst, double **vtm, double **rtm)
{
	t_transform	fn[3];

	fn[sphere] = transform_sphere;
	fn[plane] = transform_plane;
	fn[cylinder] = transform_cylinder;
	while (lst)
	{
		fn[lst->type](&lst->object, vtm, rtm);
		lst = lst->next;
	}
}
