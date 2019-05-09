/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:07:16 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/09 10:36:29 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char *standard_commands[] = {
	"",
	\
	NULL
};

char *msg_digest_commands[] = {
	"md5",
	"sha256",
	\
	NULL
};

char *cipher_commands[] = {
	"",
	\
	NULL
};

void	usage(void)
{
	ft_printf("Usage: ./ft_ssl command [command opts] [command args]");
	return ;
}

void		invalid_cmd(char *cmd)
{
	int8_t	i;

	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", cmd);
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
