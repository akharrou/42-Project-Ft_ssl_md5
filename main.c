/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:30:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/18 11:49:28 by akharrou         ###   ########.fr       */
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
			compute_digests(g_ssl_commands[i], av + 1);
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
