/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 07:40:24 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/01 18:55:15 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_pipe.h"

#include <stdio.h>
#include <unistd.h> // dup dup2 pipe
#include <signal.h>
#include <stdlib.h> // malloc free

#include "execute_pipe2.h"
#include "words_util.h"
#include "execute_data.h"
#include "libft.h"
#include "error.h"
#include "environ.h"

// void	pipex(t_execute_data *child_data, int in, int out)
// {
// 	dup2(in, STDIN_FILENO);
// 	dup2(out, STDOUT_FILENO);
// 	execve(child_data->path_cmd, child_data->argument, environ);
// 	write(STDERR_FILENO, "command not found\n", 18);
// }



// static void	remove_quotes(char **words)
// {

// }
static void	find_path(t_execute_data *data)
{

}

static void	fork_setup_fd(t_execute_data *data, int in, int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
	close(in);
	fprintf(stderr, "running execve\n");
	//execve(data->command_path, data->argv, g_environ);
	error(err_child_back);
	kill(getpid(), SIGINT);
}

static int	run_pipe(t_execute_data *data, int count, int *return_val)
{
	int		i;
	int		my_pipe[2];
	int		pid;
	int		next_in;

	i = 0;
	while (i < count)
	{
		if (pipe(my_pipe))
			return (error(err_pipe));
		if (i == 0)
			next_in = 0;
		pid = fork();
		if (pid == 0)
		{
			close(my_pipe[0]);
			fork_setup_fd(data, next_in, my_pipe);
		}
		close(next_in);
		close(my_pipe[1]);
		next_in = my_pipe[0];
		i++;
	}
	*return_val = 0;
	return (0);
}

int	execute_pipe(char ***words, int *return_val)
{
	int				error;
	int				i;
	t_execute_data	*data;
	int				pipe_count;

	fprintf(stderr, "executing pipe:\n  ");
	pipe_count = count_pipes(*words);
	data = ft_calloc(1 + pipe_count, sizeof(t_execute_data));
	if (!data)
		return (1);
	i = 0;
	while (**words && !is_logic_connector(**words))
	{
		error = execute_data_create(data + i, words);
		if (error)
		{
			free(data);
			return (error);
		}
		if (**words && !is_logic_connector(**words))
			*words += 1;
		i++;
	}
	return 0;
	//return (run_pipe(data, pipe_count + 1, return_val));
}
