/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:29:57 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 22:07:39 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

typedef char *	t_string;

int			ft_strlen(const t_string str);
// t_string	*ft_strsplit(const t_string str, char c);
t_string	ft_strtrim(t_string str);
t_string	ft_strcpy(const t_string dest, const t_string src);
int			ft_strcmp(const t_string s1, const t_string s2);

#endif