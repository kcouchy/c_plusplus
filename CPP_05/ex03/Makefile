# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 15:15:39 by kcouchma          #+#    #+#              #
#    Updated: 2024/06/03 17:39:47 by kcouchma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	Bureaucrat				\
		AForm					\
		ShrubberyCreationForm	\
		RobotomyRequestForm		\
		PresidentialPardonForm	\
		Intern					\
		main

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = bureaucrat_03

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o : %.cpp
	$(CXX) -o $@ -c $^ $(CXXFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf *_shrubbery
	rm -rf $(NAME)

re	: fclean
	make

.PHONY : all clean fclean re
