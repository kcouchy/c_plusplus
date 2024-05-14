# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 14:12:55 by kcouchma          #+#    #+#              #
#    Updated: 2024/05/02 14:26:41 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	Zombie		\
		newZombie	\
		randomChump	\
		main

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = zombies

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) -o $@ $^ $(CPPFLAGS)

%.o : %.cpp
	$(CPP) -c $^ -o $@ $(CPPFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re	: fclean
	make

.PHONY : all clean fclean re