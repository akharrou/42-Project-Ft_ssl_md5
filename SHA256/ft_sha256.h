/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:36:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/16 16:51:48 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Header File(s).
*/

# include "../Libft/Includes/libft.h"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**  Flag(s).
*/

# define O_FD   (1)
# define O_BUF  (2)

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Macro(s).
*/

# define SHA256_DIGEST_LENGTH   (32)
# define SHA256_CHUNK_LENGTH    (64)

# ifdef E
#  undef E
# endif

# define A   (ctx->state[0])
# define B   (ctx->state[1])
# define C   (ctx->state[2])
# define D   (ctx->state[3])
# define E   (ctx->state[4])
# define F   (ctx->state[5])
# define G   (ctx->state[6])
# define H   (ctx->state[7])

# define A1  (ctx_prime.state[0])
# define B1  (ctx_prime.state[1])
# define C1  (ctx_prime.state[2])
# define D1  (ctx_prime.state[3])
# define E1  (ctx_prime.state[4])
# define F1  (ctx_prime.state[5])
# define G1  (ctx_prime.state[6])
# define H1  (ctx_prime.state[7])

# define CH(e, f, g)   ((e & f) ^ ((~e) & g))
# define MAJ(a, b, c)  ((a & b) ^ (a & c) ^ (b & c))
# define EP0(a) (ROTATE_RIGHT(a, 2) ^ ROTATE_RIGHT(a, 13) ^ ROTATE_RIGHT(a, 22))
# define EP1(e) (ROTATE_RIGHT(e, 6) ^ ROTATE_RIGHT(e, 11) ^ ROTATE_RIGHT(e, 25))

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Structure(s).
*/

typedef struct	s_sha256_context
{
	uint64_t	bitlen;
	char		chunk[64];
	uint32_t	schedule[64];
	uint32_t	state[8];
}				t_sha256ctx;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Global(s).
*/

extern const uint32_t g_k[64];

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Main Function(s).
*/

char			*ft_sha256(void *data, int flag);

void			sha256_init(t_sha256ctx *ctx);
ssize_t			sha256_update(t_sha256ctx *ctx, void **data, int flag);
void			sha256_transform(t_sha256ctx *ctx);
void			sha256_final(t_sha256ctx *ctx, char **digest);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Utility Function(s).
*/

void			sha256_transform_init(t_sha256ctx *ctx, t_sha256ctx *ctx_prime);
void			sha256_schedule(t_sha256ctx *ctx);
void			sha256_transform_final(t_sha256ctx *ctx,
					t_sha256ctx *ctx_prime);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
