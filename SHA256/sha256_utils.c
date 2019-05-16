/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:33:23 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/16 14:07:43 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

/*
**    DESCRIPTION
**         Initialization of the auxilary context.
*/

void	sha256_transform_init(t_sha256ctx *ctx, t_sha256ctx *ctx_prime)
{
    ctx_prime->state[0] = A;
    ctx_prime->state[1] = B;
    ctx_prime->state[2] = C;
    ctx_prime->state[3] = D;
    ctx_prime->state[4] = E;
    ctx_prime->state[5] = F;
    ctx_prime->state[6] = G;
    ctx_prime->state[7] = H;
}

/*
**    DESCRIPTION
**         Obtaining the 64-entry message schedule array w[0..63]
**         of 32-bit words
*/

# define S0(w) 	(ROTATE_RIGHT(w, 7) ^ ROTATE_RIGHT(w, 18) ^ (w >> 3))
# define S1(w) 	(ROTATE_RIGHT(w, 17) ^ ROTATE_RIGHT(w, 19) ^ (w >> 10))

void	sha256_schedule(t_sha256ctx *ctx)
{
	uint32_t	i;

	i = 0;
	while (i < 16)
	{
		ctx->schedule[i] = *(uint32_t *)&ctx->chunk[i * 4];
		++i;
	}
	while (i < 64)
    {
        ctx->schedule[i] = (ctx->schedule[i - 16] + S0(ctx->schedule[i - 15]) +
							ctx->schedule[i - 7] + S1(ctx->schedule[i - 2]))
							% UINT_MAX;
		++i;
	}
	return ;
}

/*
**    DESCRIPTION
**         Updating the context to the transformed context.
*/

void	sha256_transform_final(t_sha256ctx *ctx, t_sha256ctx *ctx_prime)
{
	A = (A + ctx_prime->state[0]) % UINT_MAX;
    B = (B + ctx_prime->state[1]) % UINT_MAX;
    C = (C + ctx_prime->state[2]) % UINT_MAX;
    D = (D + ctx_prime->state[3]) % UINT_MAX;
    E = (E + ctx_prime->state[4]) % UINT_MAX;
    F = (F + ctx_prime->state[5]) % UINT_MAX;
    G = (G + ctx_prime->state[6]) % UINT_MAX;
    H = (H + ctx_prime->state[7]) % UINT_MAX;
}
