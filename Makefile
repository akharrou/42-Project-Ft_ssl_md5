# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 18:55:23 by akharrou          #+#    #+#              #
#    Updated: 2019/05/16 18:51:03 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

NAME        =   ft_ssl

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

LIBRARY     =   Libft/libft.a

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

HEADERS     =   ft_ssl.h                                                      \
                                                                              \
                ft_md5.h                                                      \
                ft_sha1.h                                                     \
                ft_sha224.h                                                   \
                ft_sha256.h                                                   \
                ft_sha384.h                                                   \
                ft_sha512.h                                                   \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SOURCES     =   main.c                                                        \
                utils.c                                                       \
                                                                              \
                $(MD5)                                                        \
                $(SHA1)                                                       \
                $(SHA224)                                                     \
                $(SHA256)                                                     \
                $(SHA384)                                                     \
                $(SHA512)                                                     \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

MD5         =   ft_md5.c                                                      \
                                                                              \
                md5_process.h                                                 \
                md5_utils.h                                                   \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SHA1      =     ft_sha1.c                                                     \
                                                                              \
                sha1_process.h                                                \
                sha1_utils.h                                                  \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SHA224      =   ft_sha224.c                                                   \
                                                                              \
                sha224_process.h                                              \
                sha224_utils.h                                                \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SHA256      =   ft_sha256.c                                                   \
                                                                              \
                sha256_process.h                                              \
                sha256_utils.h                                                \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SHA256      =   ft_sha384.c                                                   \
                                                                              \
                sha384_process.h                                              \
                sha384_utils.h                                                \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SHA256      =   ft_sha512.c                                                   \
                                                                              \
                sha512_process.h                                              \
                sha512_utils.h                                                \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

OBJECTS     =   $(SOURCES:.c=.o)

# Main — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

all: $(NAME)

$(NAME): $(LIBRARY) $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo && echo $(GREEN) "[√]     [$(NAME) Successfully Compiled!]"
	@echo $(WHITE)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(WHITE) "Compiling => " $<

$(LIBRARY):
	@make -C Libft/

# House Keeping — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

DEL = /bin/rm -rf

clean:
	@$(DEL) $(shell find . -name '*.o')
	@make clean -C Libft/

fclean: clean
	@$(DEL) $(NAME)
	@make fclean -C Libft/

re: fclean all

# Text Colorization — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

GREEN = "\033[1;32m"
WHITE = "\033[1;37m"

# Norminette Check — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

nc:
	@echo && echo $(GREEN) "Checking Norme -- Source Files:" && echo $(WHITE);
	@norminette $(shell find . -name '*.c')

nh:
	@echo && echo $(GREEN) "Checking Norme -- Header Files:" && echo $(WHITE);
	@norminette $(shell find . -name '*.h')

na: nh nc

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

.PHONY: all clean fclean re nc nh na

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
