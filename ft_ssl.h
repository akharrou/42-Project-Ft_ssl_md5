/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:31:14 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/18 08:18:44 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# include "Libft/Includes/libft.h"

# include "MD5/ft_md5.h"
# include "SHA2-224/ft_sha224.h"
# include "SHA2-256/ft_sha256.h"
# include "SHA2-384/ft_sha384.h"
# include "SHA2-512/ft_sha512.h"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
* Macro(s).
*/

# define LONGEST_OPTION 1

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
* Structure(s).
*/

typedef struct	s_ssl_command
{
	const char	*name;
	char		*(*function)(void *data, int flag);
	uint16_t	output_len;
}				t_ssl_command;

typedef struct	s_ssl_option
{
	const char	*name;
	void		(*handler)(t_ssl_command cmd, void *data, int8_t *options);
	const char	*descripton;
}				t_ssl_option;

enum			e_option_values
{
	P_OPTION = (1 << 0),
	Q_OPTION = (1 << 1),
	R_OPTION = (1 << 2),
	S_OPTION = (1 << 3),
	\
	UNKNOWN_OPTION = (1 << 31)
};

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
* Global(s).
*/

extern t_ssl_command g_standard_commands[];
extern t_ssl_command g_msg_digest_commands[];
extern t_ssl_command g_cipher_commands[];
extern t_option g_option[];

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
* Main Function(s).
*/

void			compute_digests(t_ssl_command ftptr, const char **argv);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
* Utility Function(s).
*/

void			usage(void);
void			invalid_command(const char *invalid_command);
void			unknown_option(const char **argv);

void			p_option(t_ssl_command cmd, void *data, int8_t *options);
void			q_option(t_ssl_command cmd, void *data, int8_t *options);
void			r_option(t_ssl_command cmd, void *data, int8_t *options);
void			s_option(t_ssl_command cmd, void *data, int8_t *options);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
* Global Definition(s).
*/

# ifndef FT_SSL_COMMANDS
#  define FT_SSL_COMMANDS

// typedef struct	s_ssl_command
// {
// 	const char	*name;
// 	char		*(*function)(void *data, int flag);
// }				t_ssl_command;

t_ssl_command	g_standard_commands[] =
{
	{NULL, NULL}
};

t_ssl_command	g_msg_digest_commands[] =
{
	{"md5", &ft_md5},
	{"sha224", &ft_sha224},
	{"sha256", &ft_sha256},
	{"sha384", &ft_sha384},
	{"sha512", &ft_sha512},
	\
	{NULL, NULL}
};

t_ssl_command	g_cipher_commands[] =
{
	{NULL, NULL}
};

# endif

# ifndef FT_SSL_OPTIONS
#  define FT_SSL_OPTIONS

// typedef struct	s_ssl_option
// {
// 	const char	*name;
// 	const char	*descripton;
// 	void		(*handler)(void *data, int8_t *options);
// }				t_ssl_option;

t_ssl_option	g_options[] =
{
	{"p", &p_option, "echo STDIN to STDOUT and append the checksum to STDOUT"},
	{"q", &q_option, "quiet mode"},
	{"r", &r_option, "reverse the format of the output"},
	{"s", &s_option, "print the sum of the given string"},
	\
	{NULL, NULL}
};

# endif

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
