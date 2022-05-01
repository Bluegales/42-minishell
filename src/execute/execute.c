/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 03:49:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/01 08:36:14 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

#include <unistd.h>

#include "execute_pipe.h"
#include "redirect.h"
#include "words_util.h"
#include "libft.h"

static void	skip(char ***words)
{
	int	bracket_count;

	if (***words != '(')
	{
		while (**words && !is_logic_connector(**words))
			*words += 1;
		return ;
	}
	*words += 1;
	bracket_count = 1;
	while (**words && bracket_count)
	{
		if (***words == '(')
			bracket_count++;
		if (***words == ')')
			bracket_count--;
		*words += 1;
	}
}

static void	handle_connector(char ***words, int last_return)
{
	while (**words)
	{
		printf("it...\n");
		if (ft_strncmp("||", **words, 3) == 0)
		{
			*words += 1;
			if (!last_return)
				return ;
			skip(words);
		}
		else if (ft_strncmp("&&", **words, 3) == 0)
		{
			*words += 1;
			if (last_return)
				return ;
			skip(words);
		}
	}
}

int	execute(char **words)
{
	int		error;
	int		last_return;

	last_return = 0;
	while (*words)
	{
		while (*words && **words == '(')
			words++;
		if (*words)
		{
			error = execute_pipe(&words, &last_return);
			if (error)
				return (error);
		}
		while (*words && **words == ')')
			words++;
		handle_connector(&words, last_return);
	}
	return (0);
}
