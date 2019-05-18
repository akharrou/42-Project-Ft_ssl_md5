/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 10:14:19 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/18 10:32:19 by akharrou         ###   ########.fr       */
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
	char	*digest;

	if (data != NULL)
	{
		digest = cmd.function(data, O_BUF);
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
	}
	return ;
}

void			compute_digests(t_ssl_command cmd, const char **argv)
{
	int8_t		options;
	int			fd;
	int			i;
	int			j;

	while ((*(++argv)) && (*argv)[0] == '-')
	{
		i = -1;
		if (ft_strcmp(*argv, "-s"))
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
