/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 13:43:57 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/19 15:49:54 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			compute_digests(t_ssl_command cmd, const char **av)
{
	int8_t		options;
	int			i;

	while (*av && (*av)[0] == '-')
	{
		if (ft_strcmp(*av, "-s") == 0)
			break ;
		i = 0;
		while (g_ssl_options[++i].name != NULL)
			if (ft_strcmp((*av), g_ssl_options[i].name) == 0)
			{
				FT_SSL_OPTION[i].handler(cmd, NULL, &options);
				break ;
			}
		if (g_ssl_options[i].name == NULL)
			EXIT(unknown_option(*av));
	}
	while (*av && ft_strcmp(*av, "-s") == 0)
	{
		FT_SSL_STRING.handler(cmd, (void *)(*(++av)), &options);
		if (*av)
			++av;
	}
	while (*av)
		FT_SSL_DEFAULT.handler(cmd, (void *)(*(av++)), &options);
}
