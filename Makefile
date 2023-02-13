# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:25:00 by lfarias-          #+#    #+#              #
#    Updated: 2023/02/13 13:48:25 by gcorreia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT

BUILD = UnitTests/build

$(BUILD):
	@cd UnitTests && cmake -S . -B build

test: $(BUILD)
	@cd UnitTests && cmake --build build && cd build && ctest --output-on-failure
