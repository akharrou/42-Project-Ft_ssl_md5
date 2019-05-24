/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 11:37:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/23 19:40:24 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_ssl_command	g_ssl_commands[] =
{
	{ "md5", &ft_md5, 16 },
	{ "sha224", &ft_sha224, 28 },
	{ "sha256", &ft_sha256, 32 },
	{ "sha384", &ft_sha384, 48 },
	{ "sha512", &ft_sha512, 64 },
	\
	{ NULL, NULL, 0 }
};

t_ssl_option	g_ssl_options[] =
{
	{
		"-p",
		&ft_ssl_p_option,
		"echo STDIN to STDOUT and append the checksum to STDOUT"
	},
	{
		"-q",
		&ft_ssl_q_option,
		"quiet mode"
	},
	{
		"-r",
		&ft_ssl_r_option,
		"reverse the format of the output"
	},
	{
		"-s",
		&ft_ssl_s_option,
		"print the sum of the given string"
	},
	{
		NULL, NULL, NULL
	},
};
