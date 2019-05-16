/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:50:22 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/16 13:50:42 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

/*
**    DESCRIPTION
**         Denotes one MD5 transformation operation.
*/

void	md5_operation(t_md5ctx *ctx, uint32_t i, uint32_t *f, uint32_t *g)
{
	if (ROUND_1)
	{
		(*f) = F(B, C, D);
		(*g) = i;
	}
	else if (ROUND_2)
	{
		(*f) = G(B, C, D);
		(*g) = (5 * i + 1) % 16;
	}
	else if (ROUND_3)
	{
		(*f) = H(B, C, D);
		(*g) = (3 * i + 5) % 16;
	}
	else if (ROUND_4)
	{
		(*f) = I(B, C, D);
		(*g) = (7 * i) % 16;
	}
	return ;
}
