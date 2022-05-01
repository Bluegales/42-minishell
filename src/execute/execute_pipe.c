/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 07:40:24 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/01 09:14:40 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_pipe.h"

#include <stdio.h>

#include "words_util.h"
#include "execute_data.h"

static void	remove_quotes(char **words)
{

}

static char	**generate_argv(char **words)
{
	while (**words && !is_logic_connector(**words))
	{
		fprintf(stderr, "%s - ", **words);
		*words += 1;
	}
}

int	execute_pipe2(char ***words, int *return_val)
{
	int	error;
	t_execute_data data;

	while (**words && !is_logic_connector(**words))
	{
		error = execute_data_create(&data, *words);
		if (error)
			return (error);
	}
}


int	execute_pipe(char ***words, int *return_val)
{
	fprintf(stderr, "executing pipe:\n  ");
	if (***words == 'n')
		*return_val = 0;
	if (***words == 'y')
		*return_val = 1;
	while (**words && !is_logic_connector(**words))
	{
		fprintf(stderr, "%s - ", **words);
		*words += 1;
	}
	fprintf(stderr, "\n");
	return (0);
}
