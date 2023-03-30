/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:10:58 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/29 18:23:18 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	turn_up(t_scene *s)
{
	double	**matrix;

	matrix = malloc_matrix();
	if (!matrix)
		return ;
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 0.96592583;
	matrix[1][2] = 0.25881905;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = -0.25881905;
	matrix[2][2] = 0.96592583;
	matrix[2][3] = 0;
	transform_light(s->light, matrix);
	transform_objects(s->elements, matrix, NULL);
	free_matrix(matrix);
}

void	turn_down(t_scene *s)
{
	double	**matrix;

	matrix = malloc_matrix();
	if (!matrix)
		return ;
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 0.96592583;
	matrix[1][2] = -0.25881905;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0.25881905;
	matrix[2][2] = 0.96592583;
	matrix[2][3] = 0;
	transform_light(s->light, matrix);
	transform_objects(s->elements, matrix, NULL);
	free_matrix(matrix);
}

void	turn_left(t_scene *s)
{
	double	**matrix;

	matrix = malloc_matrix();
	if (!matrix)
		return ;
	matrix[0][0] = 0.96592583;
	matrix[0][1] = 0;
	matrix[0][2] = -0.25881905;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0.25881905;
	matrix[2][1] = 0;
	matrix[2][2] = 0.96592583;
	matrix[2][3] = 0;
	transform_light(s->light, matrix);
	transform_objects(s->elements, matrix, NULL);
	free_matrix(matrix);
}

void	turn_right(t_scene *s)
{
	double	**matrix;

	matrix = malloc_matrix();
	if (!matrix)
		return ;
	matrix[0][0] = 0.96592583;
	matrix[0][1] = 0;
	matrix[0][2] = 0.25881905;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = -0.25881905;
	matrix[2][1] = 0;
	matrix[2][2] = 0.96592583;
	matrix[2][3] = 0;
	transform_light(s->light, matrix);
	transform_objects(s->elements, matrix, NULL);
	free_matrix(matrix);
}
