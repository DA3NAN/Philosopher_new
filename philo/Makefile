# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 12:13:59 by adnane            #+#    #+#              #
#    Updated: 2023/06/05 16:11:29 by aait-mal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC =	$(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = philo.h
CC = cc
FLAGS = -Wall -Wextra -Werror -pthread
all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
