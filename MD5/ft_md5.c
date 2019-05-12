/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:14:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/11 19:30:59 by akharrou         ###   ########.fr       */
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
**     •  'f' is a placeholder for the padded_message of the state variables passed
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

	if (_512bit_string)
	{
		i = 0;
		while (i < SUBDIVISIONS)
		{
			(*_32bit_word)[i] = *((uint32_t *)&_512bit_string[i * 4]);
			++i;
		}
	}
	return ;
}

/*
**    DESCRIPTION
**         Denotes one operation.
*/
static void		md5_operation(t_md5 state, uint32_t i, uint32_t *f, uint32_t *g)
{
	if (ROUND_1)
	{
		(*f) = F(state.b, state.c, state.d);
		(*g) = i;
	}
	else if (ROUND_2)
	{
		(*f) = G(state.b, state.c, state.d);
		(*g) = (5 * i + 1) % 16;
	}
	else if (ROUND_3)
	{
		(*f) = H(state.b, state.c, state.d);
		(*g) = (3 * i + 5) % 16;
	}
	else if (ROUND_4)
	{
		(*f) = I(state.b, state.c, state.d);
		(*g) = (7 * i) % 16;
	}
	return ;
}

/*
**    DESCRIPTION
**         Denotes the entire process that each message chunk goes through.
*/
static t_md5	md5_process(t_md5 state, uint32_t m[SUBDIVISIONS])
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
		state_prime.b = state_prime.b + ROTATE_LEFT(f, g_s[i]);
		++i;
	}
	state.a += state_prime.a;
	state.d += state_prime.d;
	state.c += state_prime.c;
	state.b += state_prime.b;
	return (state);
}

static char		**md5_preprocess(char *msg, size_t size)
{
	char		**chunk_array;
	int32_t		len;
	int32_t		i;

	if (!msg)
		EXIT(ft_printf("%s{lred}", "error: missing input message"));
	len = (size / CHUNK_SIZE) + 1;
	if (CHUNK_SIZE - (size % CHUNK_SIZE) <= sizeof(uint64_t))
		len += 1;
	if (!(chunk_array = (char **)malloc(sizeof(char *) * (len + 1))))
		EXIT(ft_printf("%s{lred}", strerror(errno)));
	i = -1;
	ft_printf("%s\n", msg);
	while (++i < len)
	{
		chunk_array[i] = (char *)ft_malloc(CHUNK_SIZE, '\0');
		if (!chunk_array[i])
			EXIT(ft_printf("%s{lred}", strerror(errno)));
		if ((uint32_t)i * CHUNK_SIZE < size)
			ft_strncpy(chunk_array[i], msg + (i * CHUNK_SIZE), CHUNK_SIZE);
		if (0 <= size - i * CHUNK_SIZE && size - i * CHUNK_SIZE <= 56)
			chunk_array[i][size % CHUNK_SIZE] = (char)(1 << 7);
	}
	*(uint64_t *)&chunk_array[i - 1][55] = (uint64_t)size;
	chunk_array[i] = NULL;
	return (chunk_array);
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
char			*ft_md5(void *message)
{
	t_md5		state;
	const char	**chunk;
	char		*digest;
	uint32_t	m[SUBDIVISIONS];
	int32_t		i;

	chunk = (const char **)md5_preprocess((char *)message, ft_strlen(message));
	state.a = INITIALIZER_CONSTANT_A;
	state.b = INITIALIZER_CONSTANT_B;
	state.c = INITIALIZER_CONSTANT_C;
	state.d = INITIALIZER_CONSTANT_D;
	i = -1;
	while (chunk[++i] != NULL)
	{
		get_32bit_words(chunk[i], &m);
		state = md5_process(state, (uint32_t *)m);
	}
	if (!(digest = (char *)malloc(sizeof(uint32_t) * 4 + 1)))
		return (NULL);
	*(uint32_t *)&digest[0 * 4] = state.a;
	*(uint32_t *)&digest[1 * 4] = state.b;
	*(uint32_t *)&digest[2 * 4] = state.c;
	*(uint32_t *)&digest[3 * 4] = state.d;
	digest[4 * 4] = '\0';
	return (digest);
}

/*
 *
 * TEST MAIN
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int		main(void)
{

	printf("OURS: %s\n", ft_md5("kevin"));
	printf("REAL: %s\n", "9d5e3ecdeb4cdb7acfd63075ae046672");

	return (0);
}
