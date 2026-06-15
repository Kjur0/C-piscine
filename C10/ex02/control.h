/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:10:46 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/11 11:51:08 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

typedef struct s_control
{
	int		file_count;
	int		bytes_to_read;
	char	*atoi_read;
	char	**files_to_read;
}	t_control;

int			check_flag(char *str);
void		add_file_to_read(t_control *cntrl, char *filename);
void		remove_last_file(t_control *cntrl);
t_control	make_control(int argc, char **argv);

#endif
