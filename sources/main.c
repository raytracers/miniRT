/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:56:33 by lfarias-          #+#    #+#             */
/*   Updated: 2023/02/13 18:16:49 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mini_rt.h"

int	main(int argc, char **argv)
{
	int	scene_fd;

	if (validate_args(argc, argv) != 0)
		return (1);
	scene_fd = scene_open(argv[1]);
	(void)scene_fd;
	return (0);	
}
