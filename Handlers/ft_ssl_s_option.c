/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_s_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:52:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/20 10:53:40 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

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
