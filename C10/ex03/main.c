/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:40:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/13 00:03:44 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include "ft_string.h"
#include "ft_error.h"

// write
#include <unistd.h>
// malloc, free
#include <stdlib.h>

static void	init_hexdump(t_hexdump *hd)
{
	hd->is_c = 0;
	hd->file_count = 0;
	hd->files = NULL;
	hd->offset = 0;
}

static int	parse_args(t_hexdump *hd, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	hd->files = malloc(sizeof(char *) * argc);
	if (!hd->files)
		return (1);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-C") == 0)
			hd->is_c = 1;
		else
			hd->files[j++] = argv[i];
		i++;
	}
	hd->file_count = j;
	return (0);
}

static void	print_final_offset(t_hexdump *hd)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 7;
	while (i >= 0)
	{
		write(1, &hex[(hd->offset >> (i * 4)) & 0xf], 1);
		i--;
	}
	write(1, "\n", 1);
}

static int	process_files(t_hexdump *hd, char *prog)
{
	int	i;
	int	ret;

	ret = 0;
	if (hd->file_count == 0)
	{
		if (hexdump_stdin(hd) != 0)
			ret = 1;
	}
	else
	{
		i = 0;
		while (i < hd->file_count)
		{
			if (hexdump_file(hd->files[i], hd) != 0)
			{
				print_error(prog, hd->files[i]);
				ret = 1;
			}
			i++;
		}
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	t_hexdump	hd;
	int			ret;

	init_hexdump(&hd);
	if (parse_args(&hd, argc, argv) != 0)
		return (1);
	ret = process_files(&hd, argv[0]);
	if (hd.offset > 0)
		print_final_offset(&hd);
	free(hd.files);
	return (ret);
}
