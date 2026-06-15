CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := ex00/*.c

.PHONY: re clean fclean all rush02

all: rush02
rush02:
	$(CC) $(CFLAGS) $(SRCS) -o rush-02
debug: CFLAGS += -g
debug: all
re: fclean all
clean:
	rm -f rush-02
fclean: clean