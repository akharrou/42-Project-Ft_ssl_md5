/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:42:24 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/09 13:20:18 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

bool		valid_command(const char *command)
{
	return (
		ft_isstrsets(command, 3,
			standard_commands, msg_digest_commands, cipher_commands));
}

bool		known_options(const char *option)
{

}
