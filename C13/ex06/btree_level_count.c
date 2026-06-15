/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:52:48 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 21:55:37 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"


int	btree_level_count(t_btree *root)
{
	int	left_height;
	int	right_height;

	if (!root)
		return (0);
	left_height = btree_level_count(root->left);
	right_height = btree_level_count(root->right);
	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}
