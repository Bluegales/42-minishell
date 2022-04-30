/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_data2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:04:06 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 21:49:44 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_data2.h"

#include <stddef.h>

#include "execute_data.h"

int	is_new_command(char *str)
{
	if (*str == '<')
		return (1);
	if (*str == '>')
		return (1);
	if (*str == '|')
		return (1);
	if (*str == '&')
		return (1);
	return (0);
}

int	is_redirection(char *str)
{
	if (*str == '<')
		return (1);
	if (*str == '>')
		return (1);
	return (0);
}

void	cleanup_execute_data(t_execute_data *data)
{
	(void) data;
}

void	init_execute_data(t_execute_data *data, int fd_in, int fd_out)
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

	printf("arguments:\n");
	while (i < data->argc)
	{
		printf("  %s\n", data->argv[i]);
		i++;
	}
}
