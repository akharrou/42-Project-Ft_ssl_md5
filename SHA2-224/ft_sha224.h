/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:36:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/18 10:57:28 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA224_H
# define FT_SHA224_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Header File(s).
*/

# include "../Libft/Includes/libft.h"
# include "../commons.h"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Macro(s).
*/

# define SHA224_DIGEST_LENGTH   (28)
# define SHA224_CHUNK_LENGTH    (64)
# define SHA224_TOTAL_ROUNDS    (64)

# define CH(e, f, g)   ((e & f) ^ ((~e) & g))
# define MAJ(a, b, c)  ((a & b) ^ (a & c) ^ (b & c))

# define SUM0(a) (ROTR_32BITS(a, 2) ^ ROTR_32BITS(a, 13) ^ ROTR_32BITS(a, 22))
# define SUM1(e) (ROTR_32BITS(e, 6) ^ ROTR_32BITS(e, 11) ^ ROTR_32BITS(e, 25))

# define SIG0(w) (ROTR_32BITS(w, 7) ^ ROTR_32BITS(w, 18) ^ (w >> 3))
# define SIG1(w) (ROTR_32BITS(w, 17) ^ ROTR_32BITS(w, 19) ^ (w >> 10))

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Structure(s).
*/

typedef struct	s_sha224_context
{
	uint64_t	bitlen;
	char		chunk[64];
	uint32_t	schedule[64];
	uint32_t	state[8];
}				t_sha224ctx;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Global(s).
*/

extern const uint32_t g_sha224_k[64];

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Main Function(s).
*/

char			*ft_sha224(void *data, int flag);

void			sha224_init(t_sha224ctx *ctx);
ssize_t			sha224_update(t_sha224ctx *ctx, void **data, int flag);
void			sha224_transform(t_sha224ctx *ctx);
void			sha224_final(t_sha224ctx *ctx, char **digest);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Utility Function(s).
*/

void			sha224_transform_init(t_sha224ctx *ctx, t_sha224ctx *ctx_prime);
void			sha224_schedule(t_sha224ctx *ctx);
void			sha224_transform_final(t_sha224ctx *ctx,
					t_sha224ctx *ctx_prime);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
