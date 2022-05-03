/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vars2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:58:44 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 16:04:28 by pfuchs           ###   ########.fr       */
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
	ft_free_pointer_array((void **)pieces);
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
