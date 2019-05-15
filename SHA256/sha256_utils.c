/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:25:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/14 18:14:15 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

const uint32_t g_k[64] =
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,

	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,

	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,

	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,

	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,

	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,

	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,

	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

/*
**    DESCRIPTION
**         Denotes one SHA256 transformation operation.
*/

static void		    sha256_schedule(t_sha256ctx *ctx)
{
    (void)ctx;
    return;
}

/*
**    DESCRIPTION
**         Initialization of the 32 bit words denoted A, B, C, D, E, F, G, .
*/

void	            sha256_init(t_sha256ctx *ctx)
{
    ctx->len = 0;
    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
	ctx->state[2] = 0x3c6ef372;
	ctx->state[3] = 0xa54ff53a;
	ctx->state[4] = 0x510e527f;
	ctx->state[5] = 0x9b05688c;
	ctx->state[6] = 0x1f83d9ab;
	ctx->state[7] = 0x5be0cd19;
	return ;
}

/*
**    DESCRIPTION
**         Updates the context buffer & the pointer of where we
**         are in the string/file ; also keeps track of the total
**         length of the buffer/file.
*/

ssize_t			    sha256_update(t_sha256ctx *ctx, void **data, int flag)
{
	static bool	    bit_added;
	ssize_t		    ret;

	ft_bzero(ctx->chunk, 64);
	if (flag & O_FD)
		ret = read(*((int *)(*data)), ctx->chunk, 64);
	if (flag & O_BUF)
	{
		ret = (ssize_t)ft_strlen(ft_strncpy(ctx->chunk, (char *)(*data), 64));
		*((char **)data) += ret;
	}
	ctx->len += ret;
	if (0 <= ret && ret < 64 && bit_added == false)
	{
		ctx->chunk[ret] = (char)(1 << 7);
		bit_added = true;
	}
	if (0 <= ret && ret < 56)
	{
        ft_to_big_endian(&ctx->len, sizeof(uint32_t));
        *(uint64_t *)&ctx->chunk[56] = (ctx->len * 8);
        bit_added = false;
		return (0);
	}
	return (ret);
}

/*
**    DESCRIPTION
**         Denotes the transformation (64 operations) that each message chunk
**         goes through.
*/

void	            sha256_transform(t_sha256ctx *ctx, char **digest)
{
    t_sha256ctx     ctx_prime;
    int             i;

    sha256_schedule(ctx);
    i = 0;
    while (i < 64)
    {
        s0 := (w[i-15] rightrotate 7) xor (w[i-15] rightrotate 18) xor (w[i-15] rightshift 3);
        s1 := (w[i-2] rightrotate 17) xor (w[i-2] rightrotate 19) xor (w[i-2] rightshift 10);
        w[i] := w[i-16] + s0 + w[i-7] + s1;
    }

    A_ = A;
    B_ = B;
    C_ = C;
    D_ = D;
    E_ = E;
    F_ = F;
    G_ = G;
    H_ = H;

    i = 0;
    while (i < 64)
    {
        S1 := (e rightrotate 6) xor (e rightrotate 11) xor (e rightrotate 25);
        ch := (e and f) xor ((not e) and g);
        temp1 := h + S1 + ch + k[i] + w[i];
        S0 := (a rightrotate 2) xor (a rightrotate 13) xor (a rightrotate 22);
        maj := (a and b) xor (a and c) xor (b and c);
        temp2 := S0 + maj;

        H_ = G_;
        G_ = F_;
        F_ = E_;
        E_ = D_ + temp1;
        D_ = C_;
        C_ = B_;
        B_ = A_;
        A_ = temp1 + temp2;
    }

    A += A_;
    B += B_;
    C += C_;
    D += D_;
    E += E_;
    F += F_;
    G += G_;
    H += H_;
    return ;
}

/*
**    DESCRIPTION
**         Appends the 32 bit words to each other
**         (denoted as A, B, C, D, E, F, G & H)
**         to construct the final digest.
*/

void	            sha256_final(t_sha256ctx *ctx, char **digest)
{
	if (!((*digest) = (char *)ft_malloc(SHA256_DIGEST_LENGTH + 1, '\0')))
		EXIT(ft_printf("Error: %s{underlined}", strerror(errno)));
	*(uint32_t *)&(*digest)[0 * 4] = *(uint32_t *)ft_to_big_endian(&A, 4);
	*(uint32_t *)&(*digest)[1 * 4] = *(uint32_t *)ft_to_big_endian(&B, 4);
	*(uint32_t *)&(*digest)[2 * 4] = *(uint32_t *)ft_to_big_endian(&C, 4);
	*(uint32_t *)&(*digest)[3 * 4] = *(uint32_t *)ft_to_big_endian(&D, 4);
	*(uint32_t *)&(*digest)[4 * 4] = *(uint32_t *)ft_to_big_endian(&E, 4);
	*(uint32_t *)&(*digest)[5 * 4] = *(uint32_t *)ft_to_big_endian(&F, 4);
	*(uint32_t *)&(*digest)[6 * 4] = *(uint32_t *)ft_to_big_endian(&G, 4);
	*(uint32_t *)&(*digest)[7 * 4] = *(uint32_t *)ft_to_big_endian(&H, 4);
	return ;
}
