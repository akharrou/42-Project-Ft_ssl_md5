/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:30:29 by akharrou          #+#    #+#             */
/*   Updated: 2019/05/10 18:36:24 by akharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
**
**      You have to handle errors carefully. In no way can your program quit unexpectedly
**      (Segfault, bus error, double free, etc). If you are unsure, handle the errors like
**      OpenSSL.
**
**      • You are allowed the following functions:
**
**      	◦ open
**      	◦ close
**      	◦ read
**      	◦ write
**      	◦ malloc
**      	◦ free
**      	◦ strerror
**      	◦ exit
**
**      	MSG="" ; echo $MSG','$(openssl sha256 <<< "$MSG") >> msg_digests.txt
**
*/

/*
**      typedef struct	s_input_information
**      {
**      	const char	*command;
**      	t_ssl_msg	*messages;
**      	int32_t		options;
**      }				t_input;
**
**      typedef struct	s_ssl_option
**      {
**      	const char	*name;
**      	const char	*descripton;
**      	void		(*ftptr)(t_input, t_ssl_msg);
**      }				t_option;
*/

char	**ft_strtabncat(const char **dst, const char **src, long n)
{
	size_t	i;
	size_t	j;

	if (dst && src)
	{
		i = ft_strtablen(dst);
		if (i > 0)
		{
			j = 0;
			while (n-- > 0 && src[j])
				dst[i++] = src[j++];
			dst[i] = NULL;
		}
	}
	return ((char **)dst);
}

char	**ft_strtabcat(const char **dst, const char **src)
{
	size_t	i;
	size_t	j;

	if (dst && src)
	{
		i = ft_strtablen(dst);
		if (i > 0)
		{
			j = 0;
			while (src[j])
				dst[i++] = src[j++];
			dst[i] = NULL;
		}
	}
	return ((char **)dst);
}

char	**ft_strtabjoin(const char **strtab, char *str)
{
	char **new_strtab;

	if (strtab || str)
	{
		if (!str)
			return (ft_strtabdup(strtab));
		if (!strtab)
			return (ft_strtab(1, str));
		new_strtab = ft_strtabnew(ft_strtablen(strtab) + 1);
		if (!new_strtab)
			return (NULL);
		return (ft_strtabcat(ft_strtabcat(new_strtab, s1), s2));
	}
	return (NULL);
}

char	**ft_strtabjoin(const char **strtab, int strings, ...)
{
	char **new_strtab;

	if (strtab || str)
	{
		if (!str)
			return (ft_strtabdup(strtab);
		if (!strtab)
			return (ft_strtabnew(1, str));
		if (!(new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		return (ft_strcat(ft_strcat(new_str, s1), s2));
	}
	return (NULL);
}

char	*ft_strjoinfre(char const *s1, char const *s2, int free_s1, int free_s2)
{
	char *new_str;

	new_str = ft_strjoin(s1, s2);
	if (free_s1 && s1)
		free((void *)s1);
	if (free_s2 && s2)
		free((void *)s2);
	return (new_str);
}

char			**get_messages(const char **argv, int32_t options)
{
	char	**messages;
	char	*tmp;

	if (!argv)
	{
		while (!ft_readline(STDIN, *message))
		{
			ft_strtab_appendfre(messages, 1, tmp);
			free(tmp);
		}
	}
	else if (input.options & S_OPTION)
		message = input.messages[0];
	else
	{
		while ()
			message = input.messages[0];
	}
}

int				main(int ac, const char *av[])
{
	const char	**digests;
	t_input		user_input;

	if (ac < 2)
		EXIT(usage());
	user_input.command = av[1];
	if (!valid_command(user_input.command))
		EXIT(invalid_command(user_input.command));
	user_input.options = parse_options(av + 2);
	if (user_input.options & UNKNOWN_OPTION)
		EXIT(unknown_option(av + 2));
	user_input.messages = get_messages(av + 2, user_input.options);
	digests = get_digests(
		user_input.command, user_input.messages, user_input.options);
	ft_ssl_formatted_output(user_input, digest);
	return (0);
}
