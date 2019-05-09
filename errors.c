/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:07:16 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/09 13:49:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		usage(void)
{
	ft_printf("Usage: ./ft_ssl command [command opts] [command args]");
	return ;
}

void		invalid_command(const char *invalid_command)
{
	int8_t	i;

	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", invalid_command);
	ft_printf("\n");
	ft_printf("Standard commands:\n");
	i = 0;
	while (standard_commands[i])
		ft_printf("%s\n", standard_commands[i++]);
	ft_printf("\n");
	ft_printf("Message Digest commands:\n");
	i = 0;
	while (msg_digest_commands[i])
		ft_printf("%s\n", msg_digest_commands[i++]);
	ft_printf("\n");
	ft_printf("Cipher commands:\n");
	i = 0;
	while (cipher_commands[i])
		ft_printf("%s\n", cipher_commands[i++]);
	return ;
}

void		unknown_options(const char **argv)
{
	bool	unknown;
	int8_t	width;
	int32_t	i;

	unknown = false;
	while (*argv && unknown == false)
	{
		if ((*argv)[0] == '-')
		{
			unknown = true;
			i = -1;
			while (option[++i].name && unknown)
				if (ft_strcmp(option[i].name, *argv) == 0)
					unknown = false;
		}
		++argv;
	}
	ft_printf("unknown option '%s'\n", *argv);
	ft_printf("options are\n");
	width = LONGEST_OPTION;
	i = -1;
	while (option[++i].name)
		ft_printf("-%*s %s\n", width, option[i].name, option[i].descripton);
	return ;
}
