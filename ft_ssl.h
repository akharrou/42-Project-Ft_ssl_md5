/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:31:14 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/09 14:06:10 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# include "Libft/Includes/libft.h"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# ifndef FT_SSL_COMMANDS
#  define FT_SSL_COMMANDS

extern const char	*standard_commands[];
extern const char	*msg_digest_commands[];
extern const char	*cipher_commands[];

const char	*standard_commands[] = {
	\
	NULL
};

const char	*msg_digest_commands[] = {
	"md5",
	"sha256",
	\
	NULL
};

const char	*cipher_commands[] = {
	\
	NULL
};

# endif

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# ifndef FT_SSL_OPTIONS
#  define FT_SSL_OPTIONS

typedef struct	s_option
{
	const char	*name;
	const char	*descripton;
}				t_option;

extern t_option	option[];

t_option option[] = {
	{"p", "De"},
	{"q", "De"},
	{"r", "De"},
	{"s", "De"},
	\
	NULL
};

# define LONGEST_OPTION 1

enum e_options
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

typedef struct	s_ssl_message
{
	const char	*content;
	size_t		msg_length;
}				t_ssl_msg;

typedef struct	s_input_information
{
	const char	*command;
	t_ssl_msg	*messages;
	int32_t		options;
}				t_input;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

int8_t		parse_options(const char **argv);

bool		valid_command(const char *command);
bool		known_options(const char *option);

t_ssl_msg	*get_messages(int32_t options);
const char	**get_digest(const char *command, t_ssl_msg *messages,
				int32_t options);

void		ft_ssl_formatted_output();

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

void	usage(void);
void	invalid_command(const char *invalid_command);
void	unknown_option(const char **argv);

# ifdef EXIT
# undef EXIT
#  define EXIT(error_function) { error_function; exit(EXIT_FAILURE); }
# endif

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
