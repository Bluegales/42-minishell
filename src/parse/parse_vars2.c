/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vars2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:58:44 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/29 23:39:49 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#include <stdlib.h> // malloc

#include "environ.h"
#include "error.h"
#include "helper.h"
#include "libft.h"

int	cleanup(char **pieces, int error_return)
{
	char **piece_it;

	piece_it = pieces;
	while (*piece_it)
	{
		free(*piece_it);
		piece_it++;
	}
	free(pieces);
	return (error_return);
}

int	count_vars(const char *str)
{
	int		count;
	int		quote;

	count = 0;
	quote = 0;
	while (*str)
	{
		if (*str == quote)
			quote = ~quote & 1;
		if (!quote && str[0] == '$')
			count++;
		str++;
	}
	return (count);
}
