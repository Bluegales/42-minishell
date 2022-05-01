/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 08:59:10 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/01 09:06:23 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_pipe2.h"

#include "words_util.h"
#include "libft.h"

int	count_argv(char **words)
{
	int count;

	count = 0;
	while (**words && !is_logic_connector(**words))
	{
		while (**words == '<' || **words == '>')
			words += 2;
		if (*words)
		{
			count += ft_strlen(*words) + 1;
			words++;
		}
	}
	return (count);
}
