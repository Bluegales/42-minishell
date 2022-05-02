/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 07:41:48 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 07:49:04 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

#include <stdio.h>
#include <unistd.h>

#include "execute_data.h"
#include "builtin.h"

int	execute_builtin(t_execute_data *data)
{
	if (!data->builtin)
	{
		fprintf(stderr, "builtin is NULL\n");
		return (1);
	}
	data->builtin(data->argc, data->argv);
	if (data->fd_in != STDIN_FILENO)
		close(data->fd_in);
	if (data->fd_out != STDOUT_FILENO)
		close(data->fd_out);
	return (0);
}
