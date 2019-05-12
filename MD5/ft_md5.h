/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:16:15 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/12 14:49:47 by akharrou         ###   ########.fr       */
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
# include <errno.h>

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define _64_OPERATIONS     (64)
# define DIGEST_SIZE        (16)
# define CHUNK_SIZE         (64)

# define A                  (state._32bit_word[0])
# define B                  (state._32bit_word[1])
# define C                  (state._32bit_word[2])
# define D                  (state._32bit_word[3])

# define A_                 (state_prime._32bit_word[0])
# define B_                 (state_prime._32bit_word[1])
# define C_                 (state_prime._32bit_word[2])
# define D_                 (state_prime._32bit_word[3])

# define F(b, c, d)         (((b) & (c)) | ((~b) & (d)))
# define G(b, c, d)         (((b) & (d)) | ((c) & (~d)))
# define H(b, c, d)         ((b) ^ (c) ^ (d))
# define I(b, c, d)         ((c) ^ ((b) | (~d)))

# define ROUND_1            (0 <= i && i <= 15)
# define ROUND_2            (16 <= i && i <= 31)
# define ROUND_3            (32 <= i && i <= 47)
# define ROUND_4            (48 <= i && i <= 63)

# define ROTATE_LEFT(x, n)  (((x) << (n)) | ((x) >> (32 - (n))))

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef struct	s_md5_context
{
	uint32_t	_32bit_word[4];
}				t_md5;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

extern uint32_t	g_s[64];
extern uint32_t	g_k[64];

uint32_t g_s[64] =
{
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

uint32_t g_k[64] =
{
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

char		*ft_md5(void *data, int flag);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
