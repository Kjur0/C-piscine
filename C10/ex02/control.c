/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:42:40 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 22:40:20 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"
#include "ft_string.h"

// malloc, free
#include <stdlib.h>

int	check_flag(char *str)
{
	if (str[0] && str[1] && str[0] == '-' && str[1] == 'c')
	{
		if (str[2])
			return (1);
		return (2);
	}
	return (0);
}

void	add_file_to_read(t_control *cntrl, char *filename)
{
	char	**new;
	int		i;

	new = malloc((cntrl->file_count + 1) * sizeof(char *));
	if (!new)
		return ;
	i = 0;
	while (i < cntrl->file_count)
	{
		new[i] = cntrl->files_to_read[i];
		i++;
	}
	new[i] = filename;
	if (cntrl->file_count++)
		free(cntrl->files_to_read);
	cntrl->files_to_read = new;
}

void	remove_last_file(t_control *cntrl)
{
	char	**new;
	int		i;

	new = malloc(--cntrl->file_count * sizeof(char *));
	if (!new)
		return ;
	i = 0;
	while (i < cntrl->file_count)
	{
		new[i] = cntrl->files_to_read[i];
		i++;
	}
	free(cntrl->files_to_read);
	cntrl->files_to_read = new;
}

t_control	make_control(int argc, char **argv)
{
	int			i;
	t_control	control;
	int			is_c;

	control.bytes_to_read = -1;
	control.file_count = 0;
	control.files_to_read = NULL;
	i = 1;
	while (i < argc)
	{
		is_c = check_flag(argv[i]);
		add_file_to_read(&control, argv[i]);
		if (is_c)
			remove_last_file(&control);
		if (is_c == 1)
			control.bytes_to_read = ft_atoi(&argv[i][2], &control);
		if (is_c == 2)
		{
			i++;
			if (i < argc)
				control.bytes_to_read = ft_atoi(argv[i], &control);
		}
		i++;
	}
	return (control);
}
