/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:14:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/10 18:31:14 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void	get_32bit_words(const char *chunk, uint32_t (*words)[16])
{
	(void)chunk;
	(void)words;
	return ;
}

char	**md5_preprocess(char *message, size_t size)
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

t_md5	md5_process(const char *chunk, t_md5 state)
{

/*
** 	// ~ Process the message in successive 512-bit chunks: ~ //
**
** 	    // ~ Initialize hash value for this chunk: ~ //
** 	    var int A := a0
** 	    var int B := b0
** 	    var int C := c0
** 	    var int D := d0
**
** 	    // ~ Main loop: ~ //
** 	    for i from 0 to 63
**
** 	        var int F, g
**
** 	        if 0 ≤ i ≤ 15 then
** 	            F := (B and C) or ((not B) and D)
** 	            g := i
** 	        else if 16 ≤ i ≤ 31 then
** 	            F := (D and B) or ((not D) and C)
** 	            g := (5×i + 1) mod 16
** 	        else if 32 ≤ i ≤ 47 then
** 	            F := B xor C xor D
** 	            g := (3×i + 5) mod 16
** 	        else if 48 ≤ i ≤ 63 then
** 	            F := C xor (B or (not D))
** 	            g := (7×i) mod 16
**
** 	        // ~ Be wary of the below definitions of a,b,c,d ~ //
** 	        F := F + A + K[i] + M[g]
** 	        A := D
** 	        D := C
** 	        C := B
** 	        B := B + leftrotate(F, s[i])
**
** 	    end for
**
** 	    // ~ Add this chunk's hash to result so far: ~ //
** 	    a0 := a0 + A
** 	    b0 := b0 + B
** 	    c0 := c0 + C
** 	    d0 := d0 + D
**
** 	end for
*/

	(void)chunk;
	(void)state;
	return ;
}

char			*ft_md5(void *message, size_t size)
{
	t_md5		state;
	const char	**chunk;
	uint32_t	*digest;
	int32_t		i;

	chunk = (const char **)md5_preprocess((char *)message, size);
	state.a = 0x67452301;
	state.b = 0xefcdab89;
	state.c = 0x98badcfe;
	state.d = 0x10325476;
	i = 0;
	while (chunk[i] != NULL)
	{
		get_32bit_words(chunk[i], &state.m);
		state = md5_process(chunk[i], state);
		++i;
	}
	digest = (uint32_t *)malloc(sizeof(uint32_t) * 4);
	if (!digest)
		return (NULL);
	digest[0] = state.a;
	digest[1] = state.b;
	digest[2] = state.c;
	digest[3] = state.d;
	return ((char *)(&(*digest)));
}
