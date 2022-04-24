# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 12:13:51 by pfuchs            #+#    #+#              #
#    Updated: 2022/04/24 20:43:03 by pfuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src

# Compiler Variables
CC		= gcc
CFLAGSS	= -Wall -Wextra -g #-Werror -g
INCFLAG	= -I include -I libft
# File Variables
NAME	= minishell
SRC_N	= main minishell environ environ_2
SRC		= $(addsuffix .c,$(SRC_N))
OBJ		= $(addprefix _bin/,$(notdir $(SRC:.c=.o)))

$(NAME): $(OBJ) libft/libft.a
	$(CC) -pthread $(CFLAGS) -o $@ $^ -Llibft -lft -lreadline

libft/libft.a :
	(cd libft && make && make clean)

_bin :
	mkdir _bin

_bin/%.o : %.c | _bin
	$(CC) -c $(CFLAGSS) -MMD -MP $(INCFLAG) $< -o $@

clean:
	@rm -fr _bin

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

all:	$(NAME)

.PHONY: clean fclean re all

-include $(OBJ:.o=.d)
