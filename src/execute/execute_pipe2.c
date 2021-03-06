/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 08:59:10 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/01 19:09:14 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_pipe2.h"

#include <limits.h>

#include "execute_data.h"
#include "words_util.h"

#include "libft.h"

int	count_pipes(char **words)
{
	int	count;

	count = 0;
	while (*words && !is_logic_connector(*words))
	{
		if (ft_strncmp(*words, "|", 2) == 0)
			count++;
		words++;
	}
	return (count);
}
