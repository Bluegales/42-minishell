/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:44:56 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 19:46:00 by pfuchs           ###   ########.fr       */
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
	int	fd;

	fd = open(file, O_RDONLY | O_CLOEXEC, 0644);
	if (fd == -1)
	{
		perror(file);
		return (1);
	}
	data->fd_out = fd;
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
	int	fd;

	printf("output\n");
	fd = open(file, O_WRONLY | O_CREAT , 0666);
	if (fd == -1)
	{
		printf("-%s-\n", file);
		write(2, file, 20);
		perror(file);
		printf("NOOOPE\n");
		return (1);
	}
	printf("output\n");
	data->fd_out = fd;
	return (0);
}

int	redirect_output_append(t_execute_data *data, char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(file);
		return (1);
	}
	data->fd_out = fd;
	return (0);
}

int	redirect(t_execute_data *data, char *str, char *next)
{
	if (next == NULL)
	{
		error_msg(err_parse);
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
	error_msg(err_parse);
	return (err_parse);
}
