/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:36:04 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 07:48:26 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#include <stdio.h>

#include "parse_vars.h"
#include "parse_remove_quotes.h"
#include "parse_split_words.h"
#include "error.h"
#include "libft.h"

int	parse(char **str, char ***words)
{
	int		error;

	error = parse_vars(str);
	if (error)
		return (error);
	parse_remove_quotes(*str);
	*words = parse_split_words(str);
	if (!*words)
		return (e_alloc_fail);
	printf("%s", *str);
	return (error);
}
