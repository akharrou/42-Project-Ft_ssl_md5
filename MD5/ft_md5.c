/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:14:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/11 12:13:53 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  [DEFINITIONS] :
**
**     •  All variables are unsigned 32 bit and wrap modulo 2^32 when
**        calculating
**
**     •  The digest a 128-bit state is divided into four 32-bit words,
**        denoted a, b, c, and d; these 4 variables will be held in the
**        't_md5' structure.
**
**        They are initialized to certain fixed constants (given by the MD5
**        specification).
**
**     •  's' specifies the per-round shift amounts (given by the MD5
**        specification).
**
**     •  'k' specifies the per-operation constants (given by the MD5
**        specification).
**
**     •  'm' specifies an array of 32-bit blocks that a message chunk gets
**        sub-divided in.
**
**     •  'f' is a placeholder for the result of the state variables passed
**        to a non-linear function (the function is differs every 16
**        operations)
**
**     •  'i' denotes the i'th operation we are at.
**
**     •  'g' serves as an index to grab a certain 32-bit block in the array
**        'm'. 'm[g]' denotes one 32-bit block of the message input.
*/

#include "ft_md5.h"

static void		get_32bit_words(const char *_512bit_string,
					uint32_t (*_32bit_word)[SUBDIVISIONS])
{
	uint32_t	i;
	uint32_t	word_count;

	if (_512bit_string)
	{
		word_count = 0;
		i = 0;
		while ()
	}
	return ;
}

char			**md5_preprocess(char *message, size_t size)
{
/*
**	    Pre-processing: adding a single 1 bit
**
**	    	append "1" bit to message
**
**	    	Notice: the input bytes are considered as bits strings,
**	    	where the first bit is the most significant bit of the byte.[49]
**
**	    Pre-processing: padding with zeros
**
**	    	append "0" bit until message length in bits ≡ 448 (mod 512)
**	    	append original length in bits mod 264 to message
*/
}

/*
**    DESCRIPTION
**         Denotes one operation.
*/
void			md5_operation(t_md5 state, uint32_t i, uint32_t *f, uint32_t *g)
{
	if (0 <= i && i <= 15)
	{
		(*f) = (state.b & state.c) | ((~state.b) & state.d);
		(*g) = i;
	}
	else if (16 <= i && i <= 31)
	{
		(*f) = (state.d & state.b) | ((~state.d) & state.c);
		(*g) = (5 * i + 1) % 16;
	}
	else if (32 <= i && i <= 47)
	{
		(*f) = state.b ^ state.c ^ state.d;
		(*g) = (3 * i + 5) % 16;
	}
	else if (48 <= i && i <= 63)
	{
		(*f) = state.c ^ (state.b | (~state.d));
		(*g) = (7 * i) % 16;
	}
	return ;
}

/*
**    DESCRIPTION
**         Denotes the process that each message chunk goes through.
*/
t_md5			md5_process(uint32_t m[SUBDIVISIONS], t_md5 state)
{
	t_md5		state_prime;
	uint32_t	i;
	uint32_t	f;
	uint32_t	g;

	state_prime.a = state.a;
	state_prime.d = state.d;
	state_prime.c = state.c;
	state_prime.b = state.b;
	i = 0;
	while (i < TOTAL_OPERATIONS)
	{
		md5_operation(state_prime, i, &f, &g);
		f = f + state_prime.a + g_k[i] + m[g];
		state_prime.a = state_prime.d;
		state_prime.d = state_prime.c;
		state_prime.c = state_prime.b;
		state_prime.b = state_prime.b + (f << g_s[i]);
		++i;
	}
	state.a += state_prime.a;
	state.d += state_prime.d;
	state.c += state_prime.c;
	state.b += state_prime.b;
	return (state);
}

/*
**    NAME
**         ft_md5 -- calculate a message-digest fingerprint (checksum)
**
**    SYNOPSIS
**         #include <libft.h>
**
**         char *
**         ft_md5(void *message, size_t size)
**
**    PARAMETERS
**
**         void *message       Pointer to a message.
**
**         size_t size         Size (in bytes) of the message.
**
**    DESCRIPTION
**         The md5 utility takes as input a message of arbitrary length
**         and produces as output a 'fingerprint' or 'message digest'
**         of the input.
**
**    RETURN VALUES
**         Returns a (128 bit) message-digest.
*/
char			*ft_md5(void *message, size_t size)
{
	t_md5		state;
	const char	**chunk;
	uint32_t	*digest;
	uint32_t	m[SUBDIVISIONS];
	int32_t		i;

	chunk = (const char **)md5_preprocess((char *)message, size);
	state.a = INITIALIZER_CONSTANT_A;
	state.b = INITIALIZER_CONSTANT_B;
	state.c = INITIALIZER_CONSTANT_C;
	state.d = INITIALIZER_CONSTANT_D;
	i = -1;
	while (chunk[++i] != NULL)
	{
		get_32bit_words(chunk[i], &m);
		state = md5_process((uint32_t *)m, state);
	}
	if (!(digest = (uint32_t *)malloc((sizeof(uint32_t) * 4) + 1)))
		return (NULL);
	digest[0] = state.a;
	digest[1] = state.b;
	digest[2] = state.c;
	digest[3] = state.d;
	*(digest + (sizeof(uint32_t) * 4)) = '\0';
	return ((char *)(&(*digest)));
}
