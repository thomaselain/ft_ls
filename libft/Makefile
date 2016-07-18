# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telain <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 17:08:50 by telain            #+#    #+#              #
#    Updated: 2016/06/23 14:26:29 by telain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = "\033[0;32m"
NOCOLOR = "\033[0m"
NAME = libft.a
WFLAGS= -Wall -Werror -Wextra
SRC_DIR = src
SRC_BASE = ft_putstr.c ft_putchar.c ft_strdup.c ft_strlcpy.c ft_strlcat.c\
	  ft_strlen.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c\
	  ft_strchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strrchr.c\
	  ft_bzero.c ft_memset.c ft_memccpy.c ft_memcmp.c ft_memmove.c\
	  ft_memcpy.c ft_memchr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c\
	  ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c\
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_atoi.c ft_strncmp.c\
	  ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c\
	  ft_putnbr.c ft_putendl.c ft_strsplit.c ft_lstadd.c\
	  ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c\
	  ft_factorial.c ft_isspace.c ft_putnendl.c get_next_line.c\
	  ft_sqrt.c ft_power.c ft_swap.c ft_itoa_base.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_BASE))

HEADERS	= -Iincludes/

OBJECTS	= $(subst .c,.o,$(SRC))

CC		= gcc

.SILENT:

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	printf "\e[1;1H\e[2J\e[32m"
	printf "    .__________________________________________________________________________.\n"
	printf "    |     __      __    ______     ______                      _ __         __ |\n"
	printf "    |    / /   (_) /_  / __/ /_   / ____/___  ____ ___  ____  (_) /__  ____/ / |\n"
	printf "    |   / /   / / __ \/ /_/ __/  / /   / __ \/ __  __ \/ __ \/ / / _ \/ __  /  |\n"
	printf "    |  / /___/ / /_/ / __/ /_   / /___/ /_/ / / / / / / /_/ / / /  __/ /_/ /   |\n"
	printf "    | /_____/_/_.___/_/  \__/   \____/\____/_/ /_/ /_/ .___/_/_/\___/\__,_/    |\n"
	printf "    |                                               /_/                        |\n"
	printf "    .__________________________________________________________________________.\n\n\n\e[0m"

%.o: %.c
	@$(CC) $(WFLAGS) $(HEADERS) -c -o $@ $^
	printf "[\e[0;32m✓\e[0m] : $@"
	printf "\033[0m\n"

clean:
	@rm -rf $(OBJECTS)
	printf "\e[31m-------------------\n"
	printf "| \e[32mObjects\e[0m : Deleted \e[31m|\n"
	printf "\e[31m-------------------\e[0m\n\n"

fclean: clean
	@rm -rf $(NAME)
	printf "\e[31m-------------------\n"
	printf "| \e[32m$(NAME)\e[0m : Deleted \e[31m|\n"
	printf "\e[31m-------------------\e[0m\n\n\n"

re: fclean all

.PHONY: re fclean clean all
