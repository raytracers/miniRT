/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:55:27 by gcorreia          #+#    #+#             */
/*   Updated: 2023/03/11 11:57:37 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "types.h"

t_intersection	sphere_intersection(t_ray ray, union u_object *object);
double			quadratic_solver(double	b, double c);
