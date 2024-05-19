# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 10:52:31 by okraus            #+#    #+#              #
#    Updated: 2024/05/19 17:40:22 by okraus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	NoYouNeedForm28Bnot28C
SRCS		=	main.cpp Bureaucrat.cpp AForm.cpp colours.cpp \
				ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp
HEADERS		=	Bureaucrat.hpp AForm.hpp colours.hpp \
				ShrubberyCreationForm.hpp RobotomyRequestForm.hpp \
				PresidentialPardonForm.hpp
OBJS		=	$(SRCS:.cpp=.o)
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g
CPP			=	c++

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o:		%.cpp $(HEADERS)
			$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
