/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:42:04 by kjurkows          #+#    #+#             */
/*   Updated: 2026/01/26 18:10:28 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	is_alpha;
	int	tmp;

	i = 0;
	is_alpha = 1;
	while (str[i] && is_alpha)
	{
		tmp = (str[i] >= 'a' && str[i] <= 'z');
		tmp = tmp || (str[i] >= 'A' && str[i] <= 'Z');
		is_alpha = is_alpha && tmp;
		i++;
	}
	return (is_alpha);
}
