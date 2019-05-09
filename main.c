/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:30:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/09 14:06:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*

You have to handle errors carefully. In no way can your program quit unexpectedly
(Segfault, bus error, double free, etc). If you are unsure, handle the errors like
OpenSSL.

• You are allowed the following functions:

	◦ open
	◦ close
	◦ read
	◦ write
	◦ malloc
	◦ free
	◦ strerror
	◦ exit

	MSG="" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt

 */


int				main(int ac, const char *av[])
{
	const char	**digest;
	t_input		input;

	if (ac < 2)
		EXIT(usage());
	input.command = av[1];
	if (!valid_command(input.command))
		EXIT(invalid_command(input.command));
	input.options = parse_options(av + 2);
	if (input.options & UNKNOWN_OPTION)
		EXIT(unknown_option(av + 2));
	input.messages = get_messages(input.options);
	digest = get_digest(input.command, input.messages, input.options);
	ft_ssl_formatted_output(input.options, digest);
	return (0);
}
