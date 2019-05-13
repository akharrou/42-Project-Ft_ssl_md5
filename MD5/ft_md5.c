/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:14:48 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/13 12:27:57 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
**                             O_BUF   'data' points to a buffer
**                             O_FD    'data' points to a file descriptor
**
**                          Anything else is undefined behavior.
**
**    DESCRIPTION
**         The md5 utility takes as input some data of arbitrary length and
**         produces as output a 'fingerprint' or 'message digest' of the
**         input.
**
**    RETURN VALUES
**         Returns a (128 bit) message-digest (non-hex) string.
*/

#include "ft_md5.h"

char			*ft_md5(void *data, int flag)
{
	t_md5ctx	ctx;
	char		*digest;
	int			ret;

	md5_init(&ctx);
	if (!(ctx.buffer = (char *)malloc(CHUNK_LENGTH + 1)))
		EXIT(ft_printf("Error: %s{underlined}", strerror(errno)));
	ret = 1;
	while (ret > 0)
	{
		ret = md5_update(&ctx, &data, flag);
		md5_transform(&ctx);
	}
	free(ctx.buffer);
	if (ret < 0)
	{
		ft_printf("Error: %s{underlined}", strerror(errno));
		return (NULL);
	}
	digest = NULL;
	if (!(digest = (char *)ft_malloc(DIGEST_LENGTH + 1, '\0')))
		EXIT(ft_printf("Error: %s{underlined}", strerror(errno)));
	md5_final(&ctx, digest);
	return (digest);
}
