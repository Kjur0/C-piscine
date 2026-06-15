/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:45:13 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 23:17:27 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUF_H
# define FT_BUF_H

typedef struct s_buf
{
	char	*buf;
	int		size;
}	t_buf;

void	ft_bufpush(t_buf *buf, char *addition, int size);
char	*ft_cpy_from_buf(t_buf *buf);
int		err_free(void *ptr);

#endif
