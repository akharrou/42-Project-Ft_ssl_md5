/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:16:15 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/16 13:51:45 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  'ft_md5.h' - header file for 'ft_md5.c'
*/

#ifndef FT_MD5_H
# define FT_MD5_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# include "../Libft/Includes/libft.h"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**  MD5 'flag' argument macros.
*/

# define O_FD   (1)
# define O_BUF  (2)

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**  The macros/aliases are for more readability.
*/

# define MD5_CHUNK_LENGTH   (64)
# define MD5_DIGEST_LENGTH  (16)

# define A   (ctx->state[0])
# define B   (ctx->state[1])
# define C   (ctx->state[2])
# define D   (ctx->state[3])

# define A1  (ctx_prime.state[0])
# define B1  (ctx_prime.state[1])
# define C1  (ctx_prime.state[2])
# define D1  (ctx_prime.state[3])

# define M(g)  ((*(uint32_t *)&(ctx->chunk)[g * 4]))

# define ROUND_1  (0 <= i && i <= 15)
# define ROUND_2  (16 <= i && i <= 31)
# define ROUND_3  (32 <= i && i <= 47)
# define ROUND_4  (48 <= i && i <= 63)

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define F(b, c, d)  (((b) & (c)) | ((~b) & (d)))
# define G(b, c, d)  (((b) & (d)) | ((c) & (~d)))
# define H(b, c, d)  ((b) ^ (c) ^ (d))
# define I(b, c, d)  ((c) ^ ((b) | (~d)))

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef struct	s_md5_context
{
	uint64_t	bitlen;
	uint32_t	state[4];
	char		chunk[64];
}				t_md5ctx;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

extern uint32_t	g_s[64];
extern uint32_t	g_k[64];

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**  Main Functions.
*/

char		*ft_md5(void *data, int flag);

void		md5_init(t_md5ctx *ctx);
ssize_t		md5_update(t_md5ctx *ctx, void **data, int flag);
void		md5_transform(t_md5ctx *ctx);
void		md5_final(t_md5ctx *ctx, char **digest);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**  Utility Functions.
*/

void		md5_operation(t_md5ctx *ctx, uint32_t i, uint32_t *f, uint32_t *g);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
