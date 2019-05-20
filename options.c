/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 10:14:19 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/19 22:11:51 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
**    DESCRIPTION
**         Turns on the '-r' flag.
*/

void		ft_ssl_r_option(t_ssl_command cmd, void *data, int8_t *options)
{
	(void)cmd;
	(void)data;
	(*options) |= FT_SSL_R_OPTION;
	return ;
}

/*
**    DESCRIPTION
**         Turns on the '-q' flag.
*/

void		ft_ssl_q_option(t_ssl_command cmd, void *data, int8_t *options)
{
	(void)cmd;
	(void)data;
	(*options) |= FT_SSL_Q_OPTION;
	return ;
}

/*
**    DESCRIPTION
**         Turns on the '-p' flag and reads STDIN as input.
*/

void		ft_ssl_p_option(t_ssl_command cmd, void *data, int8_t *options)
{
	(*options) |= FT_SSL_P_OPTION;
	ft_ssl_stdin(cmd, data, options);
	return ;
}

/*
**    DESCRIPTION
**         Handles strings given as argument.
*/

void		ft_ssl_s_option(t_ssl_command cmd, void *data, int8_t *options)
{
	char	*digest;
	char	*msg;

	if (!data)
	{
		ft_printf("ft_ssl: option requires an argument -- s\n");
		usage();
		return ;
	}
	msg = ft_strdup((char *)data);
	digest = cmd.function(msg, O_BUF);
	if (digest != NULL)
	{
		if (FT_SSL_Q_OPTION & (*options))
			ft_printf("%s\n",
				ft_strhex(digest, cmd.dgst_len));
		else if (FT_SSL_R_OPTION & (*options))
			ft_printf("%s \"%s\"\n",
				ft_strhex(digest, cmd.dgst_len), (char *)data);
		else
			ft_printf("%s (\"%s\") = %s\n", ft_strtoupper((char *)cmd.name),
				(char *)data, ft_strhex(digest, cmd.dgst_len));
	}
	free(digest);
	free(msg);
}

/*
**    DESCRIPTION
**         Handles inputs coming from standard input.
*/

void		ft_ssl_stdin(t_ssl_command cmd, void *data, int8_t *options)
{
	char	*digest;
	char	*tmp;

	tmp = ft_readfiledes(STDIN);
	if (tmp != NULL)
	{
		digest = cmd.function(tmp, O_BUF);
		if (options && FT_SSL_P_OPTION & (*options))
			ft_printf("%s", tmp);
		ft_printf("%s", ft_strhex(digest, cmd.dgst_len));
		free(digest);
		free(tmp);
	}
	else
		ft_printf("Error: %s{underlined}", strerror(errno));
	(void)data;
	(void)options;
	return ;
}

/*
**    DESCRIPTION
**         Handles file names given as arguments.
*/

void		ft_ssl_file(t_ssl_command cmd, void *data, int8_t *options)
{
	char	*digest;
	int		fd;

	if (data)
	{
		digest = NULL;
		fd = open((char *)data, O_RDONLY);
		if (fd < 0)
			ft_printf("%s: %s\n", (char *)data, strerror(errno));
		else
			digest = cmd.function((void *)&fd, O_FD);
		if (digest != NULL)
		{
			if (FT_SSL_Q_OPTION & (*options))
				ft_printf("%s\n", ft_strhex(digest, cmd.dgst_len));
			else if (FT_SSL_R_OPTION & (*options))
				ft_printf("%s %s\n",
					ft_strhex(digest, cmd.dgst_len), (char *)data);
			else
				ft_printf("%s (%s) = %s\n", ft_strtoupper((char *)cmd.name),
					(char *)data, ft_strhex(digest, cmd.dgst_len));
		}
		free(digest);
	}
	(void)options;
}
