# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 14:08:35 by thomathi          #+#    #+#              #
#    Updated: 2022/03/08 13:26:09 by thomathi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror

FILES = 	isalpha \
			isdigit \
			isalnum \
			isascii \
			isprint \
			strlen \
			memset \
			bzero \
			memcpy \
			memmove \
			strlcpy \
			strlcat \
			toupper \
			tolower \
			strchr \
			strrchr \
			strncmp \
			memchr \
			memcmp \
			strnstr \
			atoi \
			calloc \
			strdup \
			substr \
			strjoin \
			strtrim \
			split \
			itoa \
			strmapi \
			striteri \
			putchar_fd \
			putstr_fd \
			putendl_fd \
			putnbr_fd \
			uitoa

FBONUS = 	lstnew \
			lstadd_front \
			lstsize \
			lstlast \
			lstadd_back \
			lstdelone \
			lstclear \
			lstiter \
			lstmap
SRCS = $(FILES:%=ft_%.c)
OBJS = $(FILES:%=ft_%.o)
BSRCS = $(FBONUS:%=ft_%.c)
BOBJS = $(FBONUS:%=ft_%.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(BOBJS)
	ar rc $(NAME) $(OBJS) $(BOBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(BOBJS)
	ar rc $(NAME) $(OBJS) $(BOBJS)

.PHONY: all clean fclean re bonus
