/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:00:57 by lfarias-          #+#    #+#             */
/*   Updated: 2023/03/12 01:57:27 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	free_resources(char *line , char **line_fields);
int		elem_exists(enum e_element e_type, t_scene *scene);
int		get_uniq_elem(enum e_element e_type, char **line_f, t_scene *scene);
int		get_primitive(enum e_element e_type, char **line_f, t_scene *scene);

#include <stdio.h>

int	scene_load(int scene_fd, t_scene *scene)
{
	enum e_element	e_type;
	char			*line;
	char			**line_fields;

	line = NULL;
	while (42)
	{
		line = get_next_line(scene_fd);
		if (!line)
			break ;
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		int line_size = ft_strlen(line);
		line[line_size - 1] = '\0';
		line_fields = ft_split(line, ' ');
		e_type = get_element(line_fields[0]);	
		if (e_type == nae \
			|| get_uniq_elem(e_type, &line_fields[1], scene) \
			|| get_primitive(e_type, &line_fields[1], scene))
		{
			free_resources(line, line_fields);
			return (1);
		}
		free_resources(line, line_fields);
	}
	t_elist *node = scene->elements;
	while (node)
	{
		printf("type = %d\n", node->type);
		node = node->next;
	}
	return (0);
}

void	free_resources(char *line , char **line_fields)
{
	free(line);
	ft_free_array(line_fields);
}

int	get_uniq_elem(enum e_element e_type, char **line_f, t_scene *scene)
{
	if (elem_exists(e_type, scene))
		return (1);
	if (e_type == camera)
	{
		if (init_camera(line_f, &scene->camera))
			return (1);
	}
	else if (e_type == light)
	{
		scene->light = malloc(sizeof(t_light));
		if (init_light(line_f, scene->light))
			return (1);
	}
	else if (e_type == ambient_light)
	{
		scene->a_light = malloc(sizeof(t_a_light));
		if (init_ambient_light(line_f, scene->a_light))
			return (1);
	}
	return (0);
}

int	elem_exists(enum e_element e_type, t_scene *scene)
{
	if (e_type == camera && scene->camera != NULL)
		return (1);
	if (e_type == light && scene->light != NULL)
		return (1);
	if (e_type == ambient_light && scene->a_light != NULL)
		return (1);
	return (0);
}

int get_primitive(enum e_element e_type, char **line_f, t_scene *scene)
{
	if (e_type != ambient_light && e_type != camera && e_type != light)
	{
		t_elist *new_elem = elist_new(e_type, line_f);
		if (!new_elem)
			return (1);
		elist_addback(&scene->elements, new_elem);
	}
	return (0);
}
