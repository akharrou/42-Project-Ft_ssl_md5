/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:42:24 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/17 17:37:35 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int8_t			parse_options(const char **argv)
{
	int8_t		options;

	if (argv)
	{
		while ((*argv) && (*argv)[0] == '-')
		{

		}
	}
}

bool		valid_command(const char *command)
{
	return (
		ft_isstrsets(command, 3,
			g_standard_commands, g_msg_digest_commands, g_cipher_commands));
}


'r': can be put a million times doesnt matter and nothing happens
'p': for every 'p' after the first one you print digest of empty string i.e of: ""
's': can be specified multiple times, the argument after it is always read as a string

