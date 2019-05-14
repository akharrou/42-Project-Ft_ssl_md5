/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:36:53 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/14 11:00:06 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/****************************** MACROS ******************************/


#ifndef FT_SHA256_H
# define FT_SHA256_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Header File(s).
*/

# include "../Libft/Includes/libft.h"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Macro(s).
*/

# define SHA256_DIGEST_LENGTH      (32)
# define SHA256_CHUNK_LENGTH       (64)

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Structure(s).
*/

typedef struct	s_sha256_context
{
	uint32_t	buflen;
	char		*buffer;
	uint32_t	state[8];
}				t_sha256ctx;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Global(s).
*/

extern const uint32_t g_k[64];

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
** Function Declaration(s).
*/

char		*ft_sha256(void *data, int flag);

void		sha256_init(t_sha256ctx *ctx);
ssize_t		sha256_update(t_sha256ctx *ctx, ...);
void		sha256_transform(t_sha256ctx *ctx, ...);
void		sha256_final(t_sha256ctx *ctx, ...);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
