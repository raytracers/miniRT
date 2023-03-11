/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:49:59 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/11 15:02:38 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "types.h"

double	quadratic_solver(double b, double c);
double	dot_product(t_point a, t_point b);
t_point	vector_dif(t_point a, t_point b);
t_point	vector_sum(t_point a, t_point b);
t_point	vector_scalar(t_point v, double s);
t_point	normalize(t_point v);

#endif
