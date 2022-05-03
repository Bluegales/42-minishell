/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:37:19 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 13:24:38 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The original input string gets split at every $ and the end of the variable
// creating an array of strings, where the variables are seperated
// These then get replaced and the string is merged back together
//
// EXAMPLE:
//
// TEST="my file"
// LINE="potatoe"
//
// "cat $test | grep $line?"
// [ "cat ",   "$test",       " | grep ",   "$line",       "?" ]
// [ "cat ",   "'my file'",   " | grep ",   "'potatoe'",   "?" ]
// "cat 'my file' | grep 'potatoe'?"

#include "parse_vars.h"
#include "parse_vars2.h"

#include <stdlib.h> // malloc

#include "environ.h"
#include "error.h"
#include "helper.h"
#include "libft.h"

#include <stdio.h>

static char	*merge_pieces(char **pieces)
{
	int		i;
	int		length;
	char	*str;
	char	*str_it;

	i = 0;
	length = 0;
	while (pieces[i])
	{
		length += ft_strlen(pieces[i]);
		i++;
	}
	str = malloc(length + 1);
	if (!str)
		return (NULL);
	str[length] = '\0';
	i = 0;
	str_it = str;
	while (pieces[i])
	{
		length = ft_strlen(pieces[i]);
		ft_memcpy(str_it, pieces[i], length);
		str_it += length;
		i++;
	}
	return (str);
}

static int	transform_vars(char **pieces)
{
	char	**piece_it;
	char	*value;
	char	*replacement;

	piece_it = pieces;
	while (*piece_it)
	{
		if (**piece_it == '$')
		{
			**piece_it = '\0';
			value = environ_get(*piece_it + 1);
			if (value && *value)
			{
				replacement = malloc(ft_strlen(value) + 1);
				if (!replacement)
					return (err_alloc_fail);
				//replacement[0] = '\'';
				ft_memcpy(replacement, value, ft_strlen(value) + 1);
				//ft_memcpy(replacement + ft_strlen(value) + 1, "\'\0", 2);
				free(*piece_it);
				*piece_it = replacement;
			}
		}
		piece_it++;
	}
	return (0);
}

static int	create_piece(const char **str, int offset, char ***pieces_it)
{
	if (offset)
	{
		//fprintf(stderr, "makign piece: <%.*s>\n", offset, *str); //
		**pieces_it = ft_strsub(*str, 0, offset);
		if (!**pieces_it)
			return (err_alloc_fail);
		(*pieces_it)++;
		*str += offset;
		offset = 1;
		if (**str == '\0')
			return (0);
		while (ft_isalpha((*str)[offset])
				|| (offset == 1 && (*str)[offset] == '?'))
			offset++;
		//fprintf(stderr, "makign piece: <%.*s>\n", offset, *str); //
		**pieces_it = ft_strsub(*str, 0, offset);
		if (!**pieces_it)
			return (err_alloc_fail);
		(*pieces_it)++;
		*str += offset;
	}
	return (0);
}

// returns the new value of quote depending on the current quote
// for example if the text is currently double quoted a single quote doesnt
// do anything
static int	get_quote(char c, char quote)
{
	//printf("testing char %c on quote: %c\n", c, quote);
	if (c == '\'' && quote != '\"')
	{
		if (quote == '\'')
			return (0);
		else
			return ('\'');
	}
	if (c == '\"' && quote != '\'')
	{
		if (quote == '\"')
			return (0);
		else
			return ('\"');
	}
	return (quote);
}

static int	create_pieces(const char *str, char ***pieces_it)
{
	int			quote;
	int			error;
	const char	*str_it;

	quote = 0;
	str_it = str;
	//fprintf(stderr, "creating pieces out of: <%s>\n", str);
	while (*str_it)
	{
		quote = get_quote(*str_it, quote);
		if (quote != '\'' && str_it[0] == '$')
		{
			error = create_piece(&str, str_it - str, pieces_it);
			if (error)
				return (error);
		}
		str_it++;
	}
	error = create_piece(&str, str_it - str, pieces_it);
	if (error)
		return (error);
	return (0);
}

int	parse_vars(char **str)
{
	int		error;
	char	**pieces;
	char	**pieces_it;
	char	*merge;

	pieces = ft_calloc(count_vars(*str) * 2 + 2, sizeof(char *));
	if (pieces == 0)
		return (error_msg(err_alloc_fail));
	pieces_it = pieces;
	error = create_pieces(*str, &pieces_it);
	if (error)
		return (cleanup(pieces, error_msg(error)));
	error = transform_vars(pieces);
	if (error)
		return (cleanup(pieces, error_msg(error)));
	merge = merge_pieces(pieces);
	if (!merge)
		return (cleanup(pieces, error_msg(err_alloc_fail)));
	free(*str);
	*str = merge;
	return (cleanup(pieces, 0));
}
