/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:58:44 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 10:54:15 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include "control.h"
#include "ft_err.h"
#include "ft_print.h"

int	main(int argc, char **argv)
{
	const t_control	control = make_control(argc, argv);

	if (control.bytes_to_read == -2)
		return (ft_nbrerr(argv[0], control.atoi_read));
	if (control.bytes_to_read == 0)
		return (ft_log("\n"));
	if (control.file_count == 0)
		return (handle_stdin(control.bytes_to_read));
	if (control.file_count > 1)
		return (handle_files(control, argv[0]));
	else if (control.bytes_to_read > 0)
		return (handle_file_c(control.files_to_read[0],
				control.bytes_to_read, argv[0]));
	else
		return (handle_file_l(control.files_to_read[0], argv[0]));
}
