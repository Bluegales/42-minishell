/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_words.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 02:57:32 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 13:25:35 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_split_words.h"

#include <stdlib.h> // malloc free

#include "parse_split_words2.h"
#include "environ.h"
#include "libft.h"

static char	**cleanup_splits(char **splits)
{
	char	**it;

	it = splits;
	while (*it)
	{
		free(*it);
		it++;
	}
	free(splits);
	return (NULL);
}

static char	**split_words(const char *str, const char *delims)
{
	char	**splits;
	char	**it;
	int		count;

	while (*str && ft_strchr(delims, *str))
		str++;
	count = count_splits(str, delims);
	splits = ft_calloc(count + 1, sizeof(char *));
	if (!splits)
		return (NULL);
	it = splits;
	while (*str)
	{
		//printf("next location: <%s>\n", str);
		*it = ft_strsub(str, 0, split_length(str, delims));
		if (!*it)
			return (cleanup_splits(it));
		str += split_length(str, delims);
		//printf("string: <%s>\n", *it);
		str = next_split_location(str, delims);
		it++;
	}
	return (splits);
}

char	**parse_split_words(char *str)
{
	char	*delim;

	delim = environ_get("IFS");
	if (!delim)
		return (split_words(str, " \t\n"));
	else
		return (split_words(str, delim));
}
