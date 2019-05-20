/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_s_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:52:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/20 12:56:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    DESCRIPTION
**         Handles strings given as argument.
*/

#include "../ft_ssl.h"

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
	digest = ft_strhexfre(cmd.function(msg, O_BUF), cmd.dgst_len);
	if (digest != NULL)
	{
		if (FT_SSL_Q_OPTION & (*options))
			ft_printf("%s\n", digest);
		else if (FT_SSL_R_OPTION & (*options))
			ft_printf("%s \"%s\"\n", digest, (char *)data);
		else
			ft_printf("%s (\"%s\") = %s\n", ft_strtoupper((char *)cmd.name),
				(char *)data, digest);
	}
	free(digest);
	free(msg);
}
