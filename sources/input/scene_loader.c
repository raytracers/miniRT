/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:00:57 by lfarias-          #+#    #+#             */
/*   Updated: 2023/04/10 19:21:39 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

#define SCENE_EOF -1
#define SCENE_EMPTY_LN 1 

void	free_resources(char *line, char **line_fields);
int		get_line_fields(int scene_fd, char **line, char ***line_fields);
int		get_uniq_elem(enum e_element et, char **lf, t_scene *scene, int ln);
int		get_primitive(enum e_element et, char **line_f, t_scene *scene, int ln);

int	scene_load(int scene_fd, t_scene *scene)
{
	enum e_element	e_type;
	int				op_code;
	char			*line;
	char			**ln_fields;
	static int		ln = 0;

	while (++ln)
	{
		op_code = get_line_fields(scene_fd, &line, &ln_fields);
		if (op_code == SCENE_EOF)
			break ;
		if (op_code == SCENE_EMPTY_LN)
			continue ;
		e_type = get_element(ln_fields[0], ln);
		if (e_type == nae || get_uniq_elem(e_type, &ln_fields[1], scene, ln) \
			|| get_primitive(e_type, &ln_fields[1], scene, ln))
		{
			free_resources(line, ln_fields);
			get_next_line(GNL_FLUSH);
			return (1);
		}
		free_resources(line, ln_fields);
	}
	get_next_line(GNL_FLUSH);
	return (0);
}

int	get_line_fields(int scene_fd, char **line, char ***line_fields)
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
	*line_fields = ft_split(*line, ' ');
	if (**line_fields == NULL || *line_fields[0][0] == '\0')
	{
		free_resources(*line, *line_fields);
		return (SCENE_EMPTY_LN);
	}
	return (0);
}

void	free_resources(char *line, char **line_fields)
{
	free(line);
	ft_free_array(line_fields);
}

int	get_uniq_elem(enum e_element e_type, char **line_f, t_scene *scene, int ln)
{
	int	op_code;

	op_code = 0;
	if (e_type >= sphere && e_type <= cone)
		return (0);
	if ((e_type == camera && scene->camera != NULL) \
		|| (e_type == light && scene->light != NULL) \
		|| (e_type == ambient_light && scene->a_light != NULL))
	{
		print_scene_error(err_obj_dup, ln);
		return (1);
	}
	if (e_type == camera)
		op_code = init_camera(line_f, &scene->camera);
	else if (e_type == light)
		op_code = init_light(line_f, &scene->light);
	else if (e_type == ambient_light)
		op_code = init_ambient_light(line_f, &scene->a_light);
	if (op_code != 0)
		print_scene_error(op_code, ln);
	return (op_code);
}

int	get_primitive(enum e_element e_type, char **line_f, t_scene *scene, int ln)
{
	t_elist	*new_elem;
	int		op_code;

	new_elem = NULL;
	if (e_type != ambient_light && e_type != camera && e_type != light)
	{
		new_elem = elist_new(e_type, line_f, &op_code);
		if (!new_elem)
		{
			print_scene_error(op_code, ln);
			return (1);
		}
		elist_addback(&scene->elements, new_elem);
	}
	return (0);
}
