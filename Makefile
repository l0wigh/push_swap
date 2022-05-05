# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 11:17:33 by thomathi          #+#    #+#              #
#    Updated: 2022/05/04 16:35:34 by thomathi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRCS		= 	srcs/push_swap.c \
				srcs/push_swap_utils.c \
				srcs/push_swap_pushcmd.c \
				srcs/push_swap_swapcmd.c \
				srcs/push_swap_rotatecmd.c \
				srcs/push_swap_reversecmd.c
NAME		= push_swap
OBJS_DIR	= objs/
PROJECT_H	= srcs/push_swap.h
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
CC			= gcc
ADD_LIB		= libpushswap.a
CC_FLAGS	= -Wall -Werror -Wextra -g3

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED)
	@make -C ft_printf
	@cp ft_printf/libftprintf.a .
	@mv libftprintf.a libpushswap.a
	@ar rc libpushswap.a $(OBJECTS_PREFIXED)
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) $(ADD_LIB)
	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"

all: $(NAME)

clean:
	@cd ft_printf && make fclean
	@rm -rf $(OBJS_DIR)
	@rm libpushswap.a
	@printf "\033[2K\r${GRN}[CLEAN]${RST} done$(END)"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[2K\r${GRN}[FCLEAN]${RST} done$(END)"

re: fclean all

.PHONY:		all clean fclean re
