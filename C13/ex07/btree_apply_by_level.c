/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:54:18 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/13 00:02:27 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static void	(*g_applyf)(void *item, int current_level, int is_first_elem);

int	btree_level_count(t_btree *root)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	if (left > right)
		return (left + 1);
	return (right + 1);
}

void	process_level(t_btree *root, int target, int current, int *count)
{
	if (!root)
		return ;
	if (current == target)
	{
		(*g_applyf)(root->item, target, (*count == 0));
		*count += 1;
	}
	if (current < target)
	{
		process_level(root->left, target, current + 1, count);
		process_level(root->right, target, current + 1, count);
	}
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	levels;
	int	i;
	int	count;

	if (!root || !applyf)
		return ;
	g_applyf = applyf;
	levels = btree_level_count(root);
	i = 0;
	while (i < levels)
	{
		count = 0;
		process_level(root, i, 0, &count);
		i++;
	}
}
