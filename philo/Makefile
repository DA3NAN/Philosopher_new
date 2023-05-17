# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adnane <adnane@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 12:13:59 by adnane            #+#    #+#              #
#    Updated: 2023/05/17 13:10:42 by adnane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC =	$(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEADER = philo.h
CC = cc
FLAGS = -Wall -Wextra -Werror -g -pthread

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
