# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/10 17:51:59 by kjurkows          #+#    #+#              #
#    Updated: 2026/02/12 23:20:07 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_err.c ft_tail.c ft_print.c ft_string.c main.c control.c ft_lines.c ft_buf.c ft_util.c
OBJS = $(SRCS:.c=.o)
NAME = ft_tail

all: $(NAME)

debug: CFLAGS += -g -fdiagnostics-color=always
debug: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re debug
