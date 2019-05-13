/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:16:15 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/13 12:19:56 by akharrou         ###   ########.fr       */
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
**
**  MD5 'flag' argument macros.
**
*/

# define O_FD               (1)
# define O_BUF              (2)

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
**
**  The macros/aliases are for more readability.
**
*/

# define _64_OPERATIONS     (64)
# define CHUNK_LENGTH       (64)
# define DIGEST_LENGTH      (16)

# define A                  (ctx->word[0])
# define B                  (ctx->word[1])
# define C                  (ctx->word[2])
# define D                  (ctx->word[3])

# define A_                 (ctx_prime.word[0])
# define B_                 (ctx_prime.word[1])
# define C_                 (ctx_prime.word[2])
# define D_                 (ctx_prime.word[3])

# define M(g)               ((*(uint32_t *)&(ctx->buffer)[g * 4]))

# define ROUND_1            (0 <= i && i <= 15)
# define ROUND_2            (16 <= i && i <= 31)
# define ROUND_3            (32 <= i && i <= 47)
# define ROUND_4            (48 <= i && i <= 63)

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define F(b, c, d)         (((b) & (c)) | ((~b) & (d)))
# define G(b, c, d)         (((b) & (d)) | ((c) & (~d)))
# define H(b, c, d)         ((b) ^ (c) ^ (d))
# define I(b, c, d)         ((c) ^ ((b) | (~d)))

# define ROTATE_LEFT(x, n)  (((x) << (n)) | ((x) >> (32 - (n))))

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef struct	s_md5_context
{
	uint32_t	word[4];
	char		*buffer;
}				t_md5ctx;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

extern uint32_t	g_s[64];
extern uint32_t	g_k[64];

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

char		*ft_md5(void *data, int flag);

void		md5_init(t_md5ctx *ctx);
ssize_t		md5_update(t_md5ctx *ctx, void **data, int flag);
void		md5_transform(t_md5ctx *ctx);
void		md5_final(t_md5ctx *ctx, char *digest);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
