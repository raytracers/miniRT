/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_z_axis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:10:58 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/29 18:45:01 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

void	spin_left(t_scene *s)
{
	double	**matrix;

	matrix = malloc_matrix();
	if (!matrix)
		return ;
	matrix[0][0] = 0.96592583;
	matrix[0][1] = 0.25881905;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = -0.25881905;
	matrix[1][1] = 0.96592583;
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

void	spin_right(t_scene *s)
{
	double	**matrix;

	matrix = malloc_matrix();
	if (!matrix)
		return ;
	matrix[0][0] = 0.96592583;
	matrix[0][1] = -0.25881905;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0.25881905;
	matrix[1][1] = 0.96592583;
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
