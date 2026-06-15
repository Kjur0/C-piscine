/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:34:45 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 22:38:49 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "errors.h"

#include <stdlib.h>

t_dict	*dict_init(int size)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	dict->size = size;
	dict->key = malloc(sizeof(t_string) * size);
	dict->value = malloc(sizeof(t_string) * size);
	return (dict);
}

void	dict_destroy(t_dict *dict)
{
	int	i;

	i = 0;
	while (i < dict->size)
	{
		free(dict->key[i]);
		free(dict->value[i]);
		i++;
	}
	free(dict->key);
	free(dict->value);
	free(dict);
}

int	dict_add(t_dict *dict, t_string key, t_string value)
{
	t_string	*keys;
	t_string	*values;
	int			i;

	if (!key || !value)
		return ((long)error_dict());
	if (!ft_strlen(key) || !ft_strlen(value))
		return (0);
	keys = malloc(sizeof(t_string) * (dict->size + 1));
	values = malloc(sizeof(t_string) * (dict->size + 1));
	i = 0;
	while (i < dict->size)
	{
		keys[i] = dict->key[i];
		values[i] = dict->value[i];
		i++;
	}
	keys[i] = key;
	values[i] = value;
	free(dict->key);
	free(dict->value);
	dict->key = keys;
	dict->value = values;
	dict->size++;
	return (1);
}
