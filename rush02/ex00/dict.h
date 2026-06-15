/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:29:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 22:38:05 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include "ft_string.h"

typedef struct s_dict
{
	t_string	*key;
	t_string	*value;
	int			size;
}	t_dict;

t_dict	*dict_init(int size);
void	dict_destroy(t_dict *dict);
int		dict_add(t_dict *dict, t_string key, t_string value);

#endif