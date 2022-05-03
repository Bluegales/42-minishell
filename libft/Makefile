# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 02:09:09 by pfuchs            #+#    #+#              #
#    Updated: 2022/05/03 16:24:42 by pfuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler Variables
CC		= cc
CFLAGSS	= -Wall -Wextra -Werror
INCFLAG	= -I .
AR		= ar
ARFLAGS = -rcs
# File Variables
NAME	= libft.a
MAIN	= isalpha isdigit isalnum isascii isprint strlen\
		memset memcmp memcpy memchr memmove\
		strcpy strncpy strlcpy strcat strlcat strnstr strchr strrchr strncmp\
		strdup strsub strjoin strtrim strsplit\
		atoi itoa calloc\
		free_pointer_array strjoin_array
MAINFILES	= $(addprefix ft_,$(addsuffix .c, $(MAIN)))
OBJ	= $(addprefix _bin/,$(MAINFILES:.c=.o))

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

_bin :
	mkdir _bin

_bin/%.o : %.c | _bin
	@$(CC) -c $(CFLAGSS) -MMD -MP $(INCFLAG) $< -o $@

clean:
	@rm -fr _bin

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

all:	$(NAME)

.PHONY: clean fclean re all

-include $(OBJ:.o=.d)
