/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:31:14 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/19 09:19:58 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Header File(s).
*/

# include "Libft/Includes/libft.h"

# include "Commands/MD5/ft_md5.h"
# include "Commands/SHA2-224/ft_sha224.h"
# include "Commands/SHA2-256/ft_sha256.h"
# include "Commands/SHA2-384/ft_sha384.h"
# include "Commands/SHA2-512/ft_sha512.h"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Macro(s).
*/

# define LONGEST_OPTION (1)

# define STANDARD_COMMANDS_COUNT  (0)
# define DIGEST_COMMANDS_COUNT    (5)
# define CIPHER_COMMANDS_COUNT    (0)

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Structure(s).
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
	S_OPTION = (1 << 3)
};

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Global(s).
*/

extern t_ssl_command g_ssl_commands[];
extern t_ssl_option g_ssl_options[];

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Main Function(s).
*/

void			compute_digests(t_ssl_command ftptr, const char **argv);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Utility Function(s).
*/

void			usage(void);
void			invalid_command(const char *invalid_command);
void			unknown_option(const char *argv);

void			p_option(t_ssl_command cmd, void *data, int8_t *options);
void			q_option(t_ssl_command cmd, void *data, int8_t *options);
void			r_option(t_ssl_command cmd, void *data, int8_t *options);
void			s_option(t_ssl_command cmd, void *data, int8_t *options);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
