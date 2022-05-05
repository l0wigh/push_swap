# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 14:08:35 by thomathi          #+#    #+#              #
#    Updated: 2022/03/30 11:50:44 by thomathi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror

FILES = ft_printf supfunc supfunc2 parser pointerparser
SRCS = $(FILES:%=%.c)
OBJS = $(FILES:%=%.o)

NAME = libftprintf.a


GRAY = \033[0;90m
DARK = \033[0;30m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C libft
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@ar rc $(NAME) $(OBJS)
			@printf "$(GREEN)ft_printf is Compiled!\n"

%.o: 		%.c
			@printf "$(YELLOW)Compiling: $< $(BLUE)\n"
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -rf $(OBJS)
			@make clean -C libft
			@printf "$(CYAN)ft_printf Cleaned\n"

fclean:		clean
			@rm -f $(NAME)
			@rm -f libft/libft.a
			@printf "$(MAGENTA)Fully Cleaned\n"

re:			fclean all
			@printf "$(GREEN)Rebuild Done\n"

norm:
			@printf "$(DARK)\n"
			@norminette

.PHONY:		all clean fclean re norm
