/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:42:24 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/17 16:47:16 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

bool		valid_command(const char *command)
{
	return (
		ft_isstrsets(command, 3,
			g_standard_commands, g_msg_digest_commands, g_cipher_commands));
}
