# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 14:12:55 by kcouchma          #+#    #+#              #
#    Updated: 2024/05/06 11:38:23 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	HumanA	\
		HumanB	\
		Weapon	\
		main

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = violence

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