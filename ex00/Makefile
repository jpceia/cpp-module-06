# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpceia <joao.p.ceia@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 13:03:46 by jpceia            #+#    #+#              #
#    Updated: 2021/12/19 02:31:19 by jpceia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= scalar_conversion

SRCS 		= main.cpp

CXX	 		= clang++
RM   		= rm -f

FLAGS_WARN	= -Wall -Werror -Wextra -pedantic-errors

CXXFLAGS 	= $(FLAGS_WARN) -std=c++98 

all:	$(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

# Cleaning
clean:
	$(RM) $(NAME)

fclean:	clean

# Rebuild
re:	fclean all

# Debug
debug:		CXXFLAGS += $(FLAGS_DEBUG)
debug:		re

.PHONY:		all clean fclean re debug