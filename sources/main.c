/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:56:33 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/29 14:54:41 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mini_rt.h"

static void	init_scene(t_scene *scene);

int	main(int argc, char **argv)
{
	int			scene_fd;
	t_scene		scene;
	t_window	window;
	t_info		info;

	info.s = &scene;
	info.w = &window;
	if (!validate_args(argc, argv))
		return (1);
	scene_fd = scene_open(argv[1]);
	if (scene_fd < 0)
		return (2);
	init_scene(&scene);
	if (scene_load(scene_fd, &scene) || scene_check(&scene))
	{
		destroy_scene(&scene);
		return (3);
	}
	init_window(&info);
	transform_scene(&scene);
	render_scene(&scene, &window);
	mlx_loop(window.vars.mlx);
	return (0);
}

static void	init_scene(t_scene *scene)
{
	scene->a_light = NULL;
	scene->light = NULL;
	scene->camera = NULL;
	scene->elements = NULL;
}
