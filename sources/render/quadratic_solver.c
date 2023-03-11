/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:39:41 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/11 12:26:42 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

double	quadratic_solver(double b, double c)
{
	double	delta;
	double	sol_one;
	double	sol_two;

	b *= -1;
	delta = pow(b, 2) - 4 * c;
	if (delta < 0)
		return (-1);
	delta = sqrt(delta);
	sol_one = (b + delta) / 2;
	sol_two = (b - delta) / 2;
	if (sol_one < 0 && sol_two < 0)
		return (-1);
	else if (sol_one > 0 && sol_two < 0)
		return (sol_one);
	else if (sol_two > 0 && sol_one < 0)
		return (sol_two);
	else if (sol_one < sol_two)
		return (sol_one);
	else
		return (sol_two);
}
