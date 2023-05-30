/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:56:33 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/25 19:33:47 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/mini_rt.h"

static void init_scene(t_scene *scene);
static void display_art(void);

int main(int argc, char **argv)
{
  t_scene   scene;
  t_window  window;
  t_info    info;

  display_art();
  info.s = &scene;
  info.w = &window;
  if (!validate_args(argc, argv))
    return (1);
  info.scene_fd = scene_open(argv[1]);
  if (info.scene_fd < 0)
    return (2);
  init_scene(&scene);
  log_msg("loading the scene elements");
  if (scene_load(info.scene_fd, &scene) || scene_check(&scene))
  {
    destroy_scene(&scene, info.scene_fd);
    return (3);
  }
  init_window(&info);
  transform_scene(&scene);
  render_scene(&scene, &window);
  mlx_loop(window.vars.mlx);
  return (0);
}

static void display_art(void)
{
  ft_putendl_fd("\t███╗   ███╗██╗███╗   ██╗██╗██████╗ ████████╗", STDOUT_FILENO);
  ft_putendl_fd("\t████╗ ████║██║████╗  ██║██║██╔══██╗╚══██╔══╝", STDOUT_FILENO);
  ft_putendl_fd("\t██╔████╔██║██║██╔██╗ ██║██║██████╔╝   ██║", STDOUT_FILENO);
  ft_putendl_fd("\t██║╚██╔╝██║██║██║╚██╗██║██║██╔══██╗   ██║", STDOUT_FILENO);
  ft_putendl_fd("\t██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║   ██║", STDOUT_FILENO);
  ft_putendl_fd("\t╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝   ╚═╝\n", STDOUT_FILENO);
  log_msg("starting application");
}

static void init_scene(t_scene *scene)
{
  scene->a_light = NULL;
  scene->light = NULL;
  scene->camera = NULL;
  scene->elements = NULL;
}
