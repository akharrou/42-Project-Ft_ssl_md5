/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:14:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/12 18:39:39 by akharrou         ###   ########.fr       */
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
**     •  'f' is a placeholder for the padded_message of the state variables
**        passed to a non-linear function (the function is differs every 16
**        operations)
**
**     •  'i' denotes the i'th operation we are at.
**
**     •  'g' serves as an index to grab a certain 32-bit block in a chunk.
*/

#include "ft_md5.h"

static int		get_chunk(void **data, char *chunk, int flag)
{
	static bool		bit_added = false;
	static uint64_t	len = 0;
	ssize_t			res;

	ft_bzero(chunk, 65);
	if (flag & O_FILE)
		res = read(*((int *)(*data)), chunk, CHUNK_SIZE);
	if (flag & O_BUFFER)
	{
		ft_strncpy(chunk, (const char *)(*data), CHUNK_SIZE);
		res = ft_strlen(chunk);
		*((char **)data) += res;
	}
	if (res < 0)
		return (-1);
	len += res;
	if (res == 64)
		return (1);
	if (bit_added == false)
		chunk[res] = (char)(1 << 7);
	bit_added = true;
	if (res < 56)
		*(uint64_t *)&chunk[56] = (len * 8);
	return (!(res == 0 && bit_added));
}

/*
**    DESCRIPTION
**         Denotes one operation.
*/

static void		md5_operation(t_md5 state, uint32_t i, uint32_t *f,
					uint32_t *g)
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

/*
**    DESCRIPTION
**         Denotes the entire process that each message chunk goes through.
*/

static t_md5	md5_process(t_md5 state, char chunk[65])
{
	t_md5		state_prime;
	uint32_t	i;
	uint32_t	f;
	uint32_t	g;

	A_ = A;
	B_ = B;
	C_ = C;
	D_ = D;
	i = 0;
	while (i < _64_OPERATIONS)
	{
		md5_operation(state_prime, i, &f, &g);
		f = f + A_ + g_k[i] + (*(uint32_t *)&chunk[g * 4]);
		A_ = D_;
		D_ = C_;
		C_ = B_;
		B_ += ROTATE_LEFT(f, g_s[i]);
		++i;
	}
	A += A_;
	B += B_;
	C += C_;
	D += D_;
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
**         ft_md5(void *data, int flag)
**
**    PARAMETERS
**
**         void *data       The address of a buffer or of an integer that
**                          represents a file descriptor.
**
**         int flag         The 'flag' argument indicates to what the
**                          'data' pointer points to. The avaible flags
**                          are:
**
**                              O_BUFFER   'data' points to a buffer
**                              O_FILE     'data' points to a filedescriptor
**
**                          Anything else is undefined behavior.
**
**    DESCRIPTION
**         The md5 utility takes as input a some data of arbitrary
**         length and produces as output a 'fingerprint' or 'message
**         digest' of the input.
**
**    RETURN VALUES
**         Returns a (128 bit) message-digest (non-hex) string.
*/

char		*ft_md5(void *data, int flag)
{
	t_md5	state;
	char	*digest;
	char	*chunk;
	int		res;

	A = 0x67452301;
	B = 0xefcdab89;
	C = 0x98badcfe;
	D = 0x10325476;
	if (!(chunk = (char *)malloc(CHUNK_SIZE + 1)))
		EXIT(ft_printf("%s{lred}", strerror(errno)));
	res = 1;
	while (res)
	{
		res = get_chunk(&data, chunk, flag);
		state = md5_process(state, chunk);
	}
	free(chunk);
	if (res < 0)
		EXIT(ft_printf("%s{lred}", strerror(errno)));
	if (!(digest = (char *)ft_malloc(DIGEST_SIZE + 1, '\0')))
		EXIT(ft_printf("%s{lred}", strerror(errno)));
	*(uint32_t *)&digest[0x00] = A;
	*(uint32_t *)&digest[0x04] = B;
	*(uint32_t *)&digest[0x08] = C;
	*(uint32_t *)&digest[0x0c] = D;
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
#include <fcntl.h>

int		main(int ac, char **av)
{

	// printf("\nOURS: %s\n", ft_md5("kevin", BUFFER_));
	// printf("REAL: %s\n", "9d5e3ecdeb4cdb7acfd63075ae046672");

	// printf("\nOURS: %s\n", ft_md5("browskinielbvieoaisjdioqwhdqiwd9138dh239dhsoijda0983d89h", BUFFER_));
	// printf("REAL: %s\n", "f0891b6723ceb9319ce538682db70c5b");

	//  MSG="3F[.3P[F23, P2,3FIO\0N23 F98 23BFB\\02388A G o7g \\0 8v \0 fo873gfid\0bluf g \\0  83ogf28vl \0  udyg f7\\0823fl23 gf2387f" ; ./a $MSG  && md5 -q -s $MSG

	// printf("%s\n", ft_md5(av[1], BUFFER_));

	// int fd = open(av[1], O_RDONLY);
	// printf("%s\n", ft_md5(&fd, FILE_));

	int fd = 0;
	printf("%s\n", ft_md5("some string data", BUFFER_));

	(void)av;
	(void)ac;
	return (0);
}