/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:30:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/17 16:48:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
**
**      You have to handle errors carefully. In no way can your program quit unexpectedly
**      (Segfault, bus error, double free, etc). If you are unsure, handle the errors like
**      OpenSSL.
**
**      • You are allowed the following functions:
**
**      	◦ open
**      	◦ close
**      	◦ read
**      	◦ write
**      	◦ malloc
**      	◦ free
**      	◦ strerror
**      	◦ exit
**
**      	MSG="" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt
**
**      typedef struct	s_input_information
**      {
**      	const char	*command;
**      	int32_t		options;
**      }				t_input;
**
**      typedef struct	s_ssl_option
**      {
**      	const char	*name;
**      	const char	*descripton;
**      }				t_option;
*/

int				main(int ac, const char *av[])
{
	t_input		user_input;

	if (ac < 2)
		EXIT(usage());
	user_input.command = av[1];
	if (!valid_command(user_input.command))
		EXIT(invalid_command(user_input.command));
	user_input.options = parse_options(av + 2);
	if (user_input.options & UNKNOWN_OPTION)
		EXIT(unknown_option(av + 2));

	return (0);
}
