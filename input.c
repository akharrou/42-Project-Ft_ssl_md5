/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:42:24 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/17 19:38:45 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int8_t			parse_options(const char **argv)
{
	int8_t		options;
	int			i;
	int			j;

	while (argv && (*argv)[0] == '-')
	{
		while ((*argv)[i])
		{
			while (g_option[j].name != NULL)
			{
				if ((*argv)[i] == g_option[j].name[0])
					g_option[j].command(STDIN, options);
			}
		}
	}

			if ((*argv)[i] == 'p')
				ft_printf("%s\n%s",
					argv, ft_strhex(command(STDIN, O_FD), digest_length));
			else if (r)
				options |= R_OPTION;
			else if (q)
				options |= Q_OPTION;
			else if (s && !file_encountered)
				command(++argv, O_BUF);
			else
				EXIT(unknown_option(argv));
			++argv;

		while ((*argv))
			if (fd > 0)
				command(argv, O_FD);
			else
				ft_printf("%s", )
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
