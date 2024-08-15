# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 15:55:57 by kcouchma          #+#    #+#              #
#    Updated: 2024/08/12 13:20:16 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = iter

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o : %.cpp
	$(CXX) -o $@ -c $^ $(CXXFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re	: fclean
	make

.PHONY : all clean fclean re
