/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:02:08 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 10:54:24 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include "control.h"

# define BUF_SIZE	1024

int	handle_file_c(char *filename, int count, char *prog);
int	handle_file_l(char *filename, char *prog);
int	handle_files(t_control control, char *prog);
int	handle_stdin(int count);

#endif
