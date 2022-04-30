# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 12:13:51 by pfuchs            #+#    #+#              #
#    Updated: 2022/04/30 02:39:04 by pfuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src src/environ src/helper src/parse

# Compiler Variables
CC		= gcc
CFLAGSS	= -Wall -Wextra -g #-Werror -g
INCFLAG	= -I include -I include/parse -I libft
# File Variables
NAME	= minishell
SRC_N	= main minishell environ environ_2 cmds cmd_export \
			parse parse_vars parse_vars2 parse_remove_quotes
SRC		= $(addsuffix .c,$(SRC_N))
OBJ		= $(addprefix _bin/,$(notdir $(SRC:.c=.o)))

$(NAME): $(OBJ) libft/libft.a
	$(CC) -pthread $(CFLAGS) -o $@ $^ -Llibft -lft -lreadline

libft/libft.a :
	(cd libft && make && make clean)

_bin :
	mkdir _bin

_bin/%.o : %.c | _bin
	$(CC) -c $(CFLAGSS) -MMD -MP -g $(INCFLAG) $< -o $@

clean:
	@rm -fr _bin

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

all:	$(NAME)

.PHONY: clean fclean re all

-include $(OBJ:.o=.d)
