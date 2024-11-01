# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 13:26:41 by kcouchma          #+#    #+#              #
#    Updated: 2024/10/29 13:41:05 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main	\
		RPN

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = RPN

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