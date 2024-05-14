# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 14:43:43 by kcouchma          #+#    #+#              #
#    Updated: 2024/05/10 10:37:45 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	Fixed		\
		main

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = ortho_00

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o : %.cpp
	$(CXX) -c $^ -o $@ $(CXXFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY : all clean fclean re