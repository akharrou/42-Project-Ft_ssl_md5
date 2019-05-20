/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_p_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:52:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/20 10:53:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl.h"

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
