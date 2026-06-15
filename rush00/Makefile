CC := cc
CFLAGS := -Wall -Wextra -Werror

universal_files := ex00/ft_putchar.c ex00/main.c ex00/rush.c
bonus_files := bonus/ft_putchar.c bonus/main.c bonus/rush.c bonus/ft_atoi.c bonus/rush00.c bonus/rush01.c bonus/rush02.c bonus/rush03.c bonus/rush04.c

.PHONY: all clean fclean re rush00 rush01 rush02 rush03 rush04 bonus
all: prepare rush00 rush01 rush02 rush03 rush04 bonus
rush00: prepare clean
	$(CC) $(CFLAGS) -o build/rush00 $(universal_files) ex00/rush00.c
rush01: prepare clean
	$(CC) $(CFLAGS) -o build/rush01 $(universal_files) ex00/rush01.c
rush02: prepare clean
	$(CC) $(CFLAGS) -o build/rush02 $(universal_files) ex00/rush02.c
rush03: prepare clean
	$(CC) $(CFLAGS) -o build/rush03 $(universal_files) ex00/rush03.c
rush04: prepare clean
	$(CC) $(CFLAGS) -o build/rush04 $(universal_files) ex00/rush04.c
bonus: prepare clean
	$(CC) $(CFLAGS) -o build/bonus $(bonus_files)
prepare:
	mkdir -p build
clean:
	rm -f build/*
fclean: clean
	rmdir build
re: fclean all