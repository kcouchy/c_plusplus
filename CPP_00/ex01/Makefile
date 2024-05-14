# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 14:43:31 by kcouchma          #+#    #+#              #
#    Updated: 2024/04/30 16:21:33 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	Phonebook		\
		Contact		\
		main

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) -o $@ $^ $(CPPFLAGS)

%.o : %.cpp
	$(CPP) -c -o $@ $^ $(CPPFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY : all clean fclean re