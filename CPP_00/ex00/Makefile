# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 14:43:31 by kcouchma          #+#    #+#              #
#    Updated: 2024/04/29 18:20:25 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = megaphone

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o : %.cpp
	$(CC) -c -o $@ $^ $(CFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY : all clean fclean re