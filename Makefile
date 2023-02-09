# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:25:00 by lfarias-          #+#    #+#              #
#    Updated: 2023/02/09 17:01:43 by lfarias-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT


test:
	@cd ./unit_tests/ && cmake --build ./build && cd ./build/ && ctest
