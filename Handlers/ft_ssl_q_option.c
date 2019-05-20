/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_q_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:52:36 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/20 12:15:23 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**    DESCRIPTION
**         Turns on the '-q' flag.
*/

#include "../ft_ssl.h"

void		ft_ssl_q_option(t_ssl_command cmd, void *data, int8_t *options)
{
	(void)cmd;
	(void)data;
	(*options) |= FT_SSL_Q_OPTION;
	return ;
}
