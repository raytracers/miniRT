/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:39:41 by gcorreia          #+#    #+#             */
/*   Updated: 2023/04/02 17:01:29 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

double	quadratic_solver(double a, double b, double c)
{
	double	delta;
	double	sol_one;
	double	sol_two;

	b *= -1;
	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
		return (-1);
	delta = sqrt(delta);
	sol_one = (b + delta) / (double)(2 * a);
	sol_two = (b - delta) / (double)(2 * a);
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
