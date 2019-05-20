/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:52:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/20 12:15:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    DESCRIPTION
**         Handles file names given as arguments.
*/

#include "../ft_ssl.h"

void		ft_ssl_file(t_ssl_command cmd, void *data, int8_t *options)
{
	char	*digest;
	int		fd;

	if (data)
	{
		digest = NULL;
		fd = open((char *)data, O_RDONLY);
		if (fd < 0)
			ft_printf("ft_ssl: %s: %s: %s\n",
				cmd.name, (char *)data, strerror(errno));
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
}
