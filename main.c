/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:30:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/19 14:49:21 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int ac, const char *av[])
{
	int	i;

	if (ac < 2)
	{
		usage();
		return (1);
	}
	i = 0;
	while (g_ssl_commands[i].name != NULL)
	{
		if (ft_strcmp(av[1], g_ssl_commands[i].name) == 0)
		{
			g_ssl_commands[i].name = ft_strdup(g_ssl_commands[i].name);
			compute_digests(g_ssl_commands[i], av + 2);
			free(g_ssl_commands[i].name);
			break ;
		}
		++i;
	}
	if (g_ssl_commands[i].name == NULL)
	{
		invalid_command(av[i]);
		return (2);
	}
	return (0);
}
