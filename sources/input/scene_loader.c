/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:00:57 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/12 23:07:26 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"
#include <stdio.h>

#define SCENE_EOF -1
#define SCENE_EMPTY_LN 1 

void	free_resources(char *line, char **line_fields);
int		read_line(int scene_fd, char **line);
int		get_uniq_elem(enum e_element e_type, char **line_f, t_scene *scene);
int		get_primitive(enum e_element e_type, char **line_f, t_scene *scene);

int	scene_load(int scene_fd, t_scene *scene)
{
	enum e_element	e_type;
	int				op_code;
	char			*line;
	char			**line_fields;

	line = NULL;
	while (42)
	{
		op_code = read_line(scene_fd, &line);
		if (op_code == SCENE_EOF)
			break ;
		if (op_code == SCENE_EMPTY_LN)
			continue ;
		line_fields = ft_split(line, ' ');
		e_type = get_element(line_fields[0]);
		if (e_type == nae || get_uniq_elem(e_type, &line_fields[1], scene) \
			|| get_primitive(e_type, &line_fields[1], scene))
		{
			free_resources(line, line_fields);
			return (1);
		}
		free_resources(line, line_fields);
	}
	return (0);
}

int	read_line(int scene_fd, char **line)
{
	int	line_size;

	line_size = 0;
	*line = get_next_line(scene_fd);
	if (!(*line))
		return (SCENE_EOF);
	if (**line == '\n')
	{
		free(*line);
		return (SCENE_EMPTY_LN);
	}
	line_size = ft_strlen(*line);
	if (line_size > 0 && line[0][line_size - 1] == '\n')
		line[0][line_size - 1] = '\0';
	return (0);
}

void	free_resources(char *line, char **line_fields)
{
	free(line);
	ft_free_array(line_fields);
}

int	get_uniq_elem(enum e_element e_type, char **line_f, t_scene *scene)
{
	if (e_type == camera && scene->camera != NULL)
		return (1);
	if (e_type == light && scene->light != NULL)
		return (1);
	if (e_type == ambient_light && scene->a_light != NULL)
		return (1);
	if (e_type == camera)
	{
		if (init_camera(line_f, &scene->camera))
			return (1);
	}
	else if (e_type == light)
	{
		if (init_light(line_f, &scene->light))
			return (1);
	}
	else if (e_type == ambient_light)
	{
		if (init_ambient_light(line_f, &scene->a_light))
			return (1);
	}
	return (0);
}

int	get_primitive(enum e_element e_type, char **line_f, t_scene *scene)
{
	t_elist	*new_elem;

	new_elem = NULL;
	if (e_type != ambient_light && e_type != camera && e_type != light)
	{
		new_elem = elist_new(e_type, line_f);
		if (!new_elem)
			return (1);
		elist_addback(&scene->elements, new_elem);
	}
	return (0);
}

/*printf("a_light: %p\n", scene->a_light);
printf("a_light ratio: %lf\n", scene->a_light->ratio);
printf("a_light color: %d\n", scene->a_light->color);
printf("camera: %p\n", scene->camera);
printf("camera origin x: %lf\n", scene->camera->origin.x);
printf("camera origin y: %lf\n", scene->camera->origin.y);
printf("camera origin z: %lf\n", scene->camera->origin.z);*/
