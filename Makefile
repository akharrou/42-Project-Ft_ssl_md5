# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 18:55:23 by akharrou          #+#    #+#              #
#    Updated: 2019/05/18 11:29:13 by akharrou         ###   ########.fr        #
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
                Commands/MD5/ft_md5.h                                         \
                                                                              \
                Commands/SHA2-224/ft_sha224.h                                 \
                Commands/SHA2-256/ft_sha256.h                                 \
                Commands/SHA2-384/ft_sha384.h                                 \
                Commands/SHA2-512/ft_sha512.h                                 \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SOURCES     =   main.c                                                        \
                compute.c                                                     \
                error.c                                                       \
                                                                              \
                $(MD5)                                                        \
                                                                              \
                $(SHA224)                                                     \
                $(SHA256)                                                     \
                $(SHA384)                                                     \
                $(SHA512)                                                     \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

MD5         =   Commands/ft_md5.c                                             \
                                                                              \
                Commands/md5_process.h                                        \
                Commands/md5_utils.h                                          \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SHA224      =   Commands/SHA2-224/ft_sha224.c                                 \
                                                                              \
                Commands/SHA2-224/sha224_process.h                            \
                Commands/SHA2-224/sha224_utils.h                              \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SHA256      =   Commands/SHA2-256/ft_sha256.c                                 \
                                                                              \
                Commands/SHA2-256/sha256_process.h                            \
                Commands/SHA2-256/sha256_utils.h                              \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SHA256      =   Commands/SHA2-384/ft_sha384.c                                 \
                                                                              \
                Commands/SHA2-384/sha384_process.h                            \
                Commands/SHA2-384/sha384_utils.h                              \

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

SHA256      =   Commands/SHA2-512/ft_sha512.c                                 \
                                                                              \
                Commands/SHA2-512/sha512_process.h                            \
                Commands/SHA2-512/sha512_utils.h                              \

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
