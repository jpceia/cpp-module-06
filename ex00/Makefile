# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jceia <jceia@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 00:21:36 by jceia             #+#    #+#              #
#    Updated: 2022/01/03 13:35:50 by jceia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = convert

INC_DIR     = headers
SRC_DIR     = src
OBJ_DIR     = obj

SRCS        = $(shell find $(SRC_DIR) -name "*.cpp" -type f)
OBJS        = $(SRCS:$(SRC_DIR)/%=$(OBJ_DIR)/%.o)

CXX          = clang++
RM           = rm -f

OS          = $(shell uname)

FLAGS_WARN  = -Wall -Werror -Wextra -pedantic-errors
FLAGS_INC   = -I$(INC_DIR)
FLAGS_DEBUG = -g -fsanitize=address -DDEBUG
FLAGS_OPT   = -O3

CXXFLAGS    = $(FLAGS_WARN) $(FLAGS_INC) -std=c++98

# Compilation
$(OBJ_DIR)/%.o:    $(SRC_DIR)/%
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Linking
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

all: $(NAME)

# Cleaning
clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

# Rebuild
re: fclean all

# Debug build
debug:      CXXFLAGS += $(FLAGS_DEBUG)
debug:      re


.PHONY:     all clean fclean re debug
