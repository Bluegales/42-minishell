/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:36:04 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 16:33:50 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#include <stddef.h>

#include "parse_vars.h"
#include "parse_remove_quotes.h"
#include "parse_split_words.h"

#include <stdio.h> // just for debugging
static void	debug(char	**words)
{
	fprintf(stderr, "parse debug: ");
	while (*words)
	{
		fprintf(stderr, "-%s-", *words);
		words++;
	}
	fprintf(stderr, "\n");
}

char	**parse(char *str)
{
	char	**words;
	char	**it;

	words = parse_split_words(str);
	debug(words);
	it = words;
	while (*it)
	{
		if (parse_vars(it))
			return (NULL);
		it++;
	}
	debug(words);
	return (words);
}
