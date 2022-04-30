/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:44:56 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 20:22:09 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"

#include <unistd.h> // open
#include <fcntl.h> // open flags
#include <stdio.h> // perror

#include "execute_data.h"
#include "error.h"
#include "libft.h"

int	redirect_input_file(t_execute_data *data, char *file)
{
	data->fd_in = open(file, O_RDONLY | O_CLOEXEC);
	if (data->fd_in == -1)
	{
		perror(NULL);
		return (1);
	}
	return (0);
}

int	redirect_input_console(t_execute_data *data, char *delim)
{
	(void) data;
	(void) delim;
	return (0);
}

int	redirect_output_file(t_execute_data *data, char *file)
{
	data->fd_out = open(file, O_WRONLY | O_CREAT);
	if (data->fd_out == -1)
	{
		perror(NULL);
		return (1);
	}
	return (0);
}

int	redirect_output_append(t_execute_data *data, char *file)
{
	data->fd_out = open(file, O_WRONLY | O_CREAT | O_APPEND);
	if (data->fd_out == -1)
	{
		perror(NULL);
		return (1);
	}
	return (0);
}

int	redirect(t_execute_data *data, char *str, char *next)
{
	if (next == NULL)
	{
		error(err_parse);
		return (err_parse);
	}
	if (ft_strncmp(str, "<", 2) == 0)
		return (redirect_input_file(data, next));
	else if (ft_strncmp(str, "<<", 3) == 0)
		return (redirect_input_console(data, next));
	else if (ft_strncmp(str, ">", 2) == 0)
		return (redirect_output_file(data, next));
	else if (ft_strncmp(str, ">>", 3) == 0)
		return (redirect_output_append(data, next));
	error(err_parse);
	return (err_parse);
}
