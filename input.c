/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:42:24 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/18 08:14:30 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			compute_digests(t_ssl_command cmd, const char **argv)
{
	int8_t		options;
	int			i;
	int			j;

	while (argv && (*argv)[0] == '-')
	{
		i = -1;
		while ((*argv)[++i])
		{
			j = -1;
			while (g_option[++j].name != NULL)
				if ((*argv)[i] == g_option[j].name[0])
					g_options[j].handler(STDIN, &options);
		}
	}
	while (argv)
	{
		if (ft_strcmp(*argv, "-s"))
			g_options[3].handler(cmd.function, &options);
		else
			cmd.function(*argv, O_FILE);
	}
}

void		r_option(t_ssl_command cmd, void *data, int8_t *options)
{
	(*options) |= R_OPTION;
	return ;
}

void		q_option(t_ssl_command cmd, void *data, int8_t *options)
{
	(*options) |= Q_OPTION;
	return ;
}

void		p_option(t_ssl_command cmd, void *data, int8_t *options)
{
	char		*digest;
	char		*buf;
	int			ret;

	ret = ft_readline(STDIN, &buf);
	if (ret < 0)
	{
		ft_printf("Error: %s{underlined}", strerror(errno));
		return ;
	}
	digest = cmd.function(STDIN, O_FD);
	if (digest)
		ft_printf("%s\n%s", buf, ft_strhex(digest, digest_length));
	return ;
}

void		s_option(t_ssl_command cmd, void *data, int8_t *options)
{
	char	*digest;

	if (data)
	{
		digest = cmd.function(data, O_BUF);
		if ((*options) & Q_OPTION)
		{
			if (digest != NULL)
				ft_print("%s\n", ft_strhex(digest, cmd.output_len));
		}
		else if ((*options) & R_OPTION)
		{
			if (digest != NULL)
				ft_print("%s \"%s\"\n",
					ft_strhex(digest, cmd.output_len), (char *)data);
		}
	}
	return ;
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
