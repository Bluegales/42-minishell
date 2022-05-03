/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_data2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:04:06 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 19:12:14 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_data2.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "execute_data.h"

int	execute_data_count(char **words)
{
	int	count = 0;

	while (*words)
	{
		if (is_new_command(*words))
			count++;
		words++;
	}
	return (count);
}

void	execute_data_cleanup(t_execute_data *data)
{
	int	i;

	i = 0;
	while (data->argv[i])
	{
		free(data->argv[i]);
		i++;
	}
	free(data->argv);
	free(data);
}

void	execute_data_cleanup_multi(t_execute_data *data, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		execute_data_cleanup(data + i);
		i++;
	}
}

void	execute_data_init(t_execute_data *data, int fd_in, int fd_out)
{
	data->argc = 0;
	data->argv = NULL;
	data->fd_in = fd_in;
	data->fd_out = fd_out;
}



#include <stdio.h>

void	debug_execution_data(t_execute_data *data)
{
	int i = 0;

	printf("arguments:   ");
	while (i < data->argc)
	{
		printf("-%s-", data->argv[i]);
		i++;
	}
	printf("\nin: %d  out: %d\n", data->fd_in, data->fd_out);
}
