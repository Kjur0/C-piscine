/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:16:46 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 23:42:10 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nbr_printer.h"

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(const t_string str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	print_trouple(t_queue *queue, const t_dict *dict, t_string nbr)
{
	const int	len = ft_strlen(nbr);
	int			i;
	t_string	tmp;

	i = 0;
	while (i < dict->size)
	{
		if (!ft_strcmp(dict->key[i], nbr))
			return (queue_add(queue, dict->value[i]));
		i++;
	}
	tmp = malloc(3);
	if (len == 3)
	{
		tmp[0] = nbr[0];
		tmp[1] = 0;
		print_trouple(queue, dict, tmp);
		(print_trouple(queue, dict, "100"));
	}
	tmp[0] = nbr[len - 2];
	tmp[1] = '0';
	tmp[2] = 0;
	print_trouple(queue, dict, tmp);
	free(tmp);
	return (print_trouple(queue, dict, &nbr[len - 1]));
}

void	print_n_ilon(t_queue *queue, const t_dict *dict, int n_lion)
{
	t_string	tmp;
	int			i;

	if (n_lion > 0)
	{
		tmp = malloc(sizeof(t_string) * (n_lion * 3 + 2));
		tmp[0] = '1';
		i = 1;
		while (i <= n_lion * 3)
		{
			tmp[i] = '0';
			i++;
		}
		tmp[i] = 0;
		i = 0;
		while (i < dict->size)
		{
			if (!ft_strcmp(dict->key[i], tmp))
				return (queue_add(queue, dict->value[i]));
			i++;
		}
		free(tmp);
	}
}

void	printer(t_queue *queue, const t_dict *dict, t_string nbr)
{
	const int	len = ft_strlen(nbr);
	const int	n_lion = (len - 1) / 3;
	const int	positions = (len - 1) % 3 + 1;
	int			i;
	t_string	cur;

	if (len > 0)
	{
		cur = malloc(4);
		i = 0;
		while (i < positions)
		{
			cur[i] = nbr[i];
			i++;
		}
		cur[i] = 0;
		print_trouple(queue, dict, cur);
		print_n_ilon(queue, dict, n_lion);
		printer(queue, dict, nbr + i);
		free(cur);
	}
}
