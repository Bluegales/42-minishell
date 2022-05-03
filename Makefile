# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 12:13:51 by pfuchs            #+#    #+#              #
#    Updated: 2022/05/03 15:03:10 by pfuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FOLDERS = builtin environ execute execute_helper helper parse
VPATH = src $(addprefix src/,builtin environ execute execute_helper helper parse)

# Compiler Variables
CC		= gcc
CFLAGSS	= -Wall -Wextra -g #-Werror -g
INCFLAG	= -I include -I libft $(addprefix -I include/,$(FOLDERS))
# File Variables
NAME	= minishell
SRC_N	= main minishell error\
			builtin $(addprefix cmd_,cd echo env export pwd unset)\
			environ environ_2\
			execute execute_pipe execute_pipe2 execute_data execute_data2 \
			redirect\
			set_path\
			words_util\
			parse parse_vars parse_vars2 parse_remove_quotes \
			parse_split_words parse_split_words2
SRC		= $(addsuffix .c,$(SRC_N))
OBJ		= $(addprefix _bin/,$(notdir $(SRC:.c=.o)))

$(NAME): $(OBJ) libft/libft.a
	$(CC) -pthread $(CFLAGS) -o $@ $^ -Llibft -lft -lreadline

libft/libft.a :
	(cd libft && make && make clean)

_bin :
	mkdir _bin

_bin/%.o : %.c | _bin
	@$(CC) -c $(CFLAGSS) -MMD -MP -g $(INCFLAG) $< -o $@

clean:
	@rm -fr _bin

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

all:	$(NAME)

.PHONY: clean fclean re all

-include $(OBJ:.o=.d)
