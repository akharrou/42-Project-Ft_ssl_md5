/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:31:14 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/17 16:44:55 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# include "Libft/Includes/libft.h"
# include <errno.h>

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef struct	s_input_information
{
	const char	*command;
	int32_t		options;
}				t_input;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# ifndef FT_SSL_COMMANDS
#  define FT_SSL_COMMANDS

extern const char *g_standard_commands[];
extern const char *g_msg_digest_commands[];
extern const char *g_cipher_commands[];

const char *g_standard_commands[] =
{
	NULL
};

const char *g_msg_digest_commands[] =
{
	"md5",
	"sha256",
	\
	NULL
};

const char *g_cipher_commands[] =
{
	NULL
};

# endif

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# ifndef FT_SSL_OPTIONS
#  define FT_SSL_OPTIONS

typedef struct	s_ssl_option
{
	const char	*name;
	const char	*descripton;
}				t_option;

extern t_option g_option[];

t_option g_option[] =
{
	{"p", "echo STDIN to STDOUT and append the checksum to STDOUT"},
	{"q", "quiet mode"},
	{"r", "reverse the format of the output"},
	{"s", "print the sum of the given string"},
	\
	{NULL, NULL}
};

#  define LONGEST_OPTION 1

enum	e_options
{
	P_OPTION = (1 << 0),
	Q_OPTION = (1 << 1),
	R_OPTION = (1 << 2),
	S_OPTION = (1 << 3),
	\
	UNKNOWN_OPTION = (1 << 31)
};

# endif

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

int8_t			parse_options(const char **argv);

bool			valid_command(const char *command);
bool			known_options(const char *option);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

void			usage(void);
void			invalid_command(const char *invalid_command);
void			unknown_option(const char **argv);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
