/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_r_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:52:18 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/20 12:15:19 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    DESCRIPTION
**         Turns on the '-r' flag.
*/

#include "../ft_ssl.h"

void		ft_ssl_r_option(t_ssl_command cmd, void *data, int8_t *options)
{
	(void)cmd;
	(void)data;
	(*options) |= FT_SSL_R_OPTION;
	return ;
}
