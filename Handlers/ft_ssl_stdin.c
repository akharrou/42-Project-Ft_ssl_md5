/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:52:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/20 10:53:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

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
		ft_printf("%s\n", ft_strhex(digest, cmd.dgst_len));
		free(digest);
		free(tmp);
	}
	else
		ft_printf("Error: %s{underlined}\n", strerror(errno));
	(void)data;
	(void)options;
	return ;
}
