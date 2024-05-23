# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 15:36:25 by kcouchma          #+#    #+#              #
#    Updated: 2024/05/16 17:23:32 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	Animal		\
		Cat			\
		Dog			\
		WrongAnimal	\
		WrongCat	\
		main

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = poly_00

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