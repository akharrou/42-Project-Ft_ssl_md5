/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 11:37:50 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/19 09:22:56 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Global Definition(s).
*/

t_ssl_command	g_ssl_commands[] =
{
	{ "md5", &ft_md5, 16},
	{ "sha224", &ft_sha224, 28},
	{ "sha256", &ft_sha256, 32},
	{ "sha384", &ft_sha384, 48},
	{ "sha512", &ft_sha512, 64},
	\
	{ NULL, NULL, 0 }
};

t_ssl_option	g_ssl_options[] =
{
	{ "p", &p_option, "echo STDIN to STDOUT and append the checksum to STDOUT"},
	{ "q", &q_option, "quiet mode" },
	{ "r", &r_option, "reverse the format of the output" },
	{ "s", &s_option, "print the sum of the given string" },
	\
	{ NULL, NULL, NULL }
};

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/
