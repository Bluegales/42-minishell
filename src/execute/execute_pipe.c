/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 07:40:24 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 19:05:58 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_pipe.h"

#include <stdio.h>
#include <unistd.h> // dup dup2 pipe
#include <signal.h>
#include <stdlib.h> // malloc free
#include <sys/types.h>
#include <sys/wait.h>

#include "execute_pipe2.h"
#include "words_util.h"
#include "execute_data.h"
#include "execute_builtin.h"
#include "libft.h"
#include "environ.h"
#include "error.h"
#include "set_path.h"

static void	fork_setup(t_execute_data *data, int in, int *pipe)
{
	close(pipe[0]);
	if (data->fd_in == STDIN_FILENO)
		dup2(in, STDIN_FILENO);
	else
		close(in);
	if (data->fd_out == STDOUT_FILENO)
		dup2(pipe[1], STDOUT_FILENO);
	else
		close(pipe[1]);
	//fprintf(stderr, "running execve\n");
	execve(data->command_path, data->argv, g_environ);
	perror(error_prefix);
	kill(getpid(), SIGINT);
}

int	run_pipe_last(t_execute_data *data, int in)
{
	int	pid;

	if (data->builtin)
	{
		if (data->fd_in == STDIN_FILENO)
			dup2(in, STDIN_FILENO);
		else
			close(in);
		data->builtin(data->argc, data->argv);
		return (0);
	}
	if (set_command_path(data))
		return (err_command);
	pid = fork();
	if (pid == 0)
	{
		if (data->fd_in == STDIN_FILENO)
			dup2(in, STDIN_FILENO);
		else
			close(in);
		execve(data->command_path, data->argv, g_environ);
		perror(error_prefix);
		kill(getpid(), SIGINT);
	}
	if (in != STDIN_FILENO)
		close(in);
	return (0);
}

int	setup_fd(t_execute_data *data, int in, int *pipe)
{
	if (pipe[0] != -1)
		close(pipe[0]);
	if (data->fd_in == STDIN_FILENO)
		dup2(in, STDIN_FILENO);
	else
		close(in);
	if (data->fd_out == STDOUT_FILENO)
		dup2(pipe[1], STDOUT_FILENO);
	else
		close(pipe[1]);
	return (0);
}

static void	builtin_setup(t_execute_data *data, int in, int *pipe)
{
	int	stdpipe[2];

	dup2(STDIN_FILENO, stdpipe[0]);
	dup2(STDOUT_FILENO, stdpipe[1]);
	setup_fd(data, in, pipe);
	execute_builtin(data);
	dup2(stdpipe[0], STDIN_FILENO);
	dup2(stdpipe[1], STDOUT_FILENO);
	if (data->fd_in != STDIN_FILENO)
		close(data->fd_in);
	if (data->fd_out != STDOUT_FILENO)
		close(data->fd_out);
}

static int	run_pipe(t_execute_data *data, int count)
{
	int		i;
	int		my_pipe[2];
	int		pid;
	int		next_in;

	i = 0;
	next_in = STDIN_FILENO;
	while (i < count - 1)
	{
		if (pipe(my_pipe))
			return (error_msg(err_pipe));
		setup_fd(data + i, next_in, my_pipe);
		if (data->builtin)
			builtin_setup(data, next_in, my_pipe);
		else
		{
			pid = fork();
			if (pid == 0)
				fork_setup(data + i, next_in, my_pipe);
			if (pid == -1)
				return (error_msg(err_fork));
		}
		if (next_in != 0)
			close(next_in);
		close(my_pipe[1]);
		next_in = my_pipe[0];
		i++;
	}
	run_pipe_last(data + i, next_in);
	execute_data_cleanup_multi(data, count);
	return (0);
}

static int	wait_for_children(int count, int *return_val)
{
	int	i;

	i = 0;
	while (i < count)
	{
		waitpid(-1, return_val, 0);
		i++;
	}
	//printf("returned with value %d\n", *return_val);
	return (0);
}

int	execute_pipe(char ***words, int *return_val)
{
	int				i;
	t_execute_data	*data;
	int				pipe_count;

	//fprintf(stderr, "executing pipe:\n  ");
	pipe_count = count_pipes(*words);
	data = ft_calloc(1 + pipe_count, sizeof(t_execute_data));
	if (!data)
		return (1);
	i = 0;
	while (**words && is_pipe(**words))
	{
		execute_data_create(data + i, words);
		if (**words && is_pipe(**words))
			*words += 1;
		i++;
	}
	if (run_pipe(data, pipe_count + 1))
		*return_val = 1;
	wait_for_children(pipe_count + 1, return_val);
	return (0);
}
