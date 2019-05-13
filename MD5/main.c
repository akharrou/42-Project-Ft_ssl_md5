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
	/* NULL IN STRING TEST */
	//  MSG="3F[.3P[F23, P2,3FIO\0N23 F98 23BFB\\02388A G o7g \\0 8v \0 fo873gfid\0bluf g \\0  83ogf28vl \0  udyg f7\\0823fl23 gf2387f" ; ./a $MSG  && md5 -q -s $MSG

	/* STRING TESTS */
	// printf("%s\n", ft_strhex(ft_md5(av[1], O_BUF)));

	/* STANDARD INPUT TESTS */
	// int fd = 0;
	// printf("%s\n", ft_strhex(ft_md5(&fd, O_FD)));

	/* FILE INPUT TESTS TESTS */
	int fd;
	int i = 1;
	while (i < ac)
	{
		fd = open(av[i++], O_RDONLY);
		printf("%s\n", ft_strhex(ft_md5(&fd, O_FD)));
	}

	(void)av;
	(void)ac;
	return (0);
}
