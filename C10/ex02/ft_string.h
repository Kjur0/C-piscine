/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:41:41 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/11 14:51:45 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "control.h"
# include "ft_buf.h"

void	ft_strcpy(char *dest, char *src, int size);
void	ft_strshft_left(char *out, int bytes_read, int count, char *buf);
int		ft_atoi(char *str, t_control *cntrl);

#endif
