/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:36:04 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 13:29:38 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#include "parse_vars.h"
#include "parse_remove_quotes.h"
#include "parse_split_words.h"


#include <stdio.h> // just for debugging
static void	debug(char	**words)
{
	while (*words)
	{
		//fprintf(stderr, "-%s-\n", *words);
		words++;
	}
}

char	**parse(char *str)
{
	char	**words;
	char	**it;

	// if (parse_vars(&str))
	// 	return (NULL);
	//parse_remove_quotes(str);
	//fprintf(stderr, "got: %s\n", str);
	words = parse_split_words(str);
	it = words;
	while (*it)
	{
		if (parse_vars(it))
			return (NULL);
		//parse_remove_quotes(*it);
		it++;
	}

	debug(words);
	return (words);
}
