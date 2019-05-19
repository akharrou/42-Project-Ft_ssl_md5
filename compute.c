/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 10:14:19 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/19 12:37:49 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		r_option(t_ssl_command cmd, void *data, int8_t *options)
{
	(void)cmd;
	(void)data;
	(*options) |= R_OPTION;
	return ;
}

void		q_option(t_ssl_command cmd, void *data, int8_t *options)
{
	(void)cmd;
	(void)data;
	(*options) |= Q_OPTION;
	return ;
}

void		p_option(t_ssl_command cmd, void *data, int8_t *options)
{
	char		*digest;
	char		*buf;
	int			ret;

	(void)options;
	(void)data;
	ret = ft_readline(STDIN, &buf);
	if (ret < 0)
	{
		ft_printf("Error: %s{underlined}", strerror(errno));
		return ;
	}
	digest = cmd.function(STDIN, O_FD);
	if (digest)
		ft_printf("%s\n%s\n", buf, ft_strhex(digest, cmd.output_len));
	return ;
}

void		s_option(t_ssl_command cmd, void *data, int8_t *options)
{
	char	*command_name;
	char	*digest;
	char	*msg;

	if (!data)
	{
		ft_printf("ft_ssl: option requires an argument -- s\n");
		EXIT(usage());
		return ;
	}
	command_name = ft_strdup(cmd.name);
	msg = ft_strdup((char *)data);
	digest = cmd.function(msg, O_BUF);
	if (Q_OPTION & (*options))
	{
		if (digest != NULL)
			ft_printf("%s\n", ft_strhex(digest, cmd.output_len));
	}
	else if (R_OPTION & (*options))
	{
		if (digest != NULL)
			ft_printf("%s \"%s\"\n",
				ft_strhex(digest, cmd.output_len), (char *)data);
	}
	else
		ft_printf("%s (\"%s\") = %s\n", ft_strtoupper((char *)command_name),
			(char *)data, ft_strhex(digest, cmd.output_len));
	free(msg);
	free(command_name);
	return ;
}

void			compute_digests(t_ssl_command cmd, const char **argv)
{
	int8_t		options;
	int			fd;
	int			i;
	int			j;

	while (*argv && (*argv)[0] == '-')
	{
		i = -1;
		if (ft_strcmp(*argv, "-s") == 0)
			g_ssl_options[3].handler(cmd, (void *)(*(++argv)), &options);
		else
			while ((*argv)[++i])
			{
				j = -1;
				while (g_ssl_options[++j].name != NULL)
					if ((*argv)[i] == g_ssl_options[j].name[0])
						g_ssl_options[j].handler(
							cmd, (void *)&(*argv)[i + 1], &options);
				if (g_ssl_options[j].name == NULL)
					EXIT(unknown_option(*argv));
			}
	}
	while (*argv)
		if ((fd = ft_open((char *)(*argv), O_RDONLY)) != -1)
			cmd.function((void *)&fd, O_FD);
}
