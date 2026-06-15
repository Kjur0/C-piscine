/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:50:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 15:55:38 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

typedef struct s_hexdump
{
	int		is_c;
	int		file_count;
	char	**files;
	int		offset;
}	t_hexdump;

int		hexdump_file(char *filename, t_hexdump *hd);
int		hexdump_stdin(t_hexdump *hd);

#endif
