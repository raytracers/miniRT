/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:43:27 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/13 14:58:52 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void destroy_scene(t_scene *scene)
{
	free(scene->a_light);
	free(scene->light);
	free(scene->camera);
	free_elist(&scene->elements);
}
