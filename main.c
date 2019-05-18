/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:30:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/17 17:16:48 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*compute_digest()
{

}

int				main(int ac, const char *av[])
{
	t_input		user_input;
	const char	**digests;

	if (ac < 2)
		EXIT(usage());
	user_input.command = av[1];
	if (!valid_command(user_input.command))
		EXIT(invalid_command(user_input.command));
	user_input.options = parse_options(av + 2);
	if (user_input.options & UNKNOWN_OPTION)
		EXIT(unknown_option(av + 2));
	compute_digests(user_input.command, user_input.options);
	return (0);
}
