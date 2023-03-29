/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:10:58 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/29 17:54:28 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	move_foreward(t_scene *s)
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
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = 10;
	transform_light(s->light, matrix);
	transform_objects(s->elements, matrix, NULL);
	free_matrix(matrix);
}

void	move_back(t_scene *s)
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
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = -10;
	transform_light(s->light, matrix);
	transform_objects(s->elements, matrix, NULL);
	free_matrix(matrix);
}

void	move_left(t_scene *s)
{
	double	**matrix;

	matrix = malloc_matrix();
	if (!matrix)
		return ;
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 10;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = 0;
	transform_light(s->light, matrix);
	transform_objects(s->elements, matrix, NULL);
	free_matrix(matrix);
}

void	move_right(t_scene *s)
{
	double	**matrix;

	matrix = malloc_matrix();
	if (!matrix)
		return ;
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = -10;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = 0;
	transform_light(s->light, matrix);
	transform_objects(s->elements, matrix, NULL);
	free_matrix(matrix);
}
