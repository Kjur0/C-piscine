/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:55:30 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/11 15:06:59 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINES_H
# define FT_LINES_H

typedef struct s_line_storage
{
	char	*lines[10];
	int		count;
}	t_line_storage;

t_line_storage	read_lines(int fd);
void			print_lines(t_line_storage line_stor);

#endif
