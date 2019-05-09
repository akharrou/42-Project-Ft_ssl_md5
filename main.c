/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:30:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/09 10:54:46 by akharrou         ###   ########.fr       */
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

	MSG="hello world" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt && \
	MSG="transcend" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt && \
	MSG="california" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt && \
	MSG="new york" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt && \
	MSG="philidelphia" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt && \
	MSG="washington" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt && \
	MSG="Washington" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt && \
	MSG="Boston" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt && \
	MSG="texas" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt && \
	MSG="boston" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt

 */

int		main(int ac, char *av[])
{
	int8_t	flags;
	char	*msg;

	if (!av[1] || !ft_isstrset(av[1], msg_digest_commands))
		EXIT(usage());
	flags = parse_flags(av + 2);

	return (0);
}
