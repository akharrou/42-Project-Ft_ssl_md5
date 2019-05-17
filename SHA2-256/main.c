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

#include "ft_sha256.h"

#ifndef SHA256_DIGEST_LENGTH
# define SHA256_DIGEST_LENGTH 32
#endif

int		main(int ac, char **av)
{
	char	*hexstr;
	int		fd;
	int		i;

	/* STRING TESTS                            -- FLAG: '-s' */
	if (ft_strcmp(av[1], "-s") == 0)
	{
		hexstr = ft_sha256(av[2], O_BUF);
		if (hexstr != NULL)
		{
			printf("%s\n", ft_strhex(hexstr, SHA256_DIGEST_LENGTH));
			free(hexstr);
		}
	}

	/* STANDARD INPUT TESTS                    -- FLAG: '-i' */
	else if (ft_strcmp(av[1], "-i") == 0)
	{
		fd = 0;
		hexstr = ft_sha256(&fd, O_FD);
		if (hexstr != NULL)
		{
			printf("%s\n", ft_strhex(hexstr, SHA256_DIGEST_LENGTH));
			free(hexstr);
		}
	}

	/* FILE INPUT TESTS TESTS                  -- FLAG: '' */
	else
	{
		i = 1;
		while (i < ac)
		{
			fd = open(av[i++], O_RDONLY);
			hexstr = ft_sha256(&fd, O_FD);
			if (hexstr != NULL)
			{
				printf("%s\n", ft_strhex(hexstr, SHA256_DIGEST_LENGTH));
				free(hexstr);
			}
		}
	}
	return (0);
}
