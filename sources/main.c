/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:56:33 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/07 16:56:01 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mini_rt.h"

int	main(int argc, char **argv)
{
	int			scene_fd;
	t_window	window;

	if (!validate_args(argc, argv))
		return (1);
	scene_fd = scene_open(argv[1]);
	if (scene_fd < 0)
		return (2);
	init_window(&window);
	mlx_loop(window.vars.mlx);
	return (0);
}
