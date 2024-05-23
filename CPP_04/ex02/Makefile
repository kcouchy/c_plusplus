# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 15:36:25 by kcouchma          #+#    #+#              #
#    Updated: 2024/05/21 13:42:52 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	A_Animal	\
		Cat			\
		Dog			\
		WrongAnimal	\
		WrongCat	\
		Brain		\
		main

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = poly_02

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) -o $@ $(SRC) $(CXXFLAGS)

%.o : %.cpp
	$(CXX) -o $@ -c $^ $(CXXFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY : all clean fclean re
