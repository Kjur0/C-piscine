# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/10 16:56:19 by kjurkows          #+#    #+#              #
#    Updated: 2026/02/10 17:02:00 by kjurkows         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	=	srcs
SRCS		=	$(SRCS_DIR)/ft_putchar.c \
				$(SRCS_DIR)/ft_swap.c \
				$(SRCS_DIR)/ft_putstr.c \
				$(SRCS_DIR)/ft_strlen.c \
				$(SRCS_DIR)/ft_strcmp.c
OBJS		=	$(SRCS:.c=.o)
NAME		=	libft.a
INCLUDES	=	includes
CC 			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PNOHY: all clean fclean re