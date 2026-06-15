# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/30 20:03:52 by kjurkows          #+#    #+#              #
#    Updated: 2026/01/31 17:33:59 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CC_FLAGS := -Wall -Wextra -Werror

NAME := rush01
SRC := ex00/*.c

.PHONY: rush01 clean fclean re all
all: rush01
rush01:
	$(CC) $(CC_FLAGS) -o $(NAME) $(SRC)
debug:
	$(CC) $(CC_FLAGS) -g -o $(NAME) $(SRC)
re: fclean all
fclean: clean
clean:
	rm -f $(NAME)
