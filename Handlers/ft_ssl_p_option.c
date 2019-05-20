/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_p_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:52:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/20 12:17:22 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    DESCRIPTION
**         Turns on the '-p' flag and reads STDIN as input.
*/

#include "../ft_ssl.h"

void		ft_ssl_p_option(t_ssl_command cmd, void *data, int8_t *options)
{
	(*options) |= FT_SSL_P_OPTION;
	ft_ssl_stdin(cmd, NULL, options);
	(void)data;
	return ;
}
