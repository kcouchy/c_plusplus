# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 13:26:41 by kcouchma          #+#    #+#              #
#    Updated: 2024/11/01 10:50:58 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main		\
		PmergeMe	\
		PmergeMeVec	\
		PmergeMeDeq

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PmergeMe

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