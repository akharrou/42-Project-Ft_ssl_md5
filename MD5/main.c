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

#include "ft_md5.h"

int		main(int ac, char **av)
{
	char	*hexstr;
	int		fd;
	int		i;

	/* STRING TESTS                            -- FLAG: '-s' */
	if (ft_strcmp(av[1], "-s") == 0)
	{
		hexstr = ft_md5(av[2], O_BUF);
		if (hexstr != NULL)
		{
			printf("%s\n", ft_strhex(hexstr, 16));
			free(hexstr);
		}
	}

	/* STANDARD INPUT TESTS                    -- FLAG: '-i' */
	else if (ft_strcmp(av[1], "-i") == 0)
	{
		fd = 0;
		hexstr = ft_md5(&fd, O_FD);
		if (hexstr != NULL)
		{
			printf("%s\n", ft_strhex(hexstr, 16));
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
			hexstr = ft_md5(&fd, O_FD);
			if (hexstr != NULL)
			{
				printf("%s\n", ft_strhex(hexstr, 16));
				free(hexstr);
			}
		}
	}
	return (0);
}
