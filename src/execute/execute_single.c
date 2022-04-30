/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 03:49:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 19:34:18 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_single.h"

#include "execute_single2.h"
#include "execution_data.h"
#include "error.h"
#include "redirect.h"
#include "libft.h"

static void	init_redirection(t_execution_data *data, int fd_in, int fd_out)
{
	int	error;

	data->argc = 0;
	data->argv = NULL;
	fd_in = fd_in;
	fd_out = fd_out;
}

int	handle_redirection(t_execution_data *data, char ***str)
{
	int	error;

	if (ft_strncmp(str, "<", 1) != 0 && ft_strncmp(str, ">", 1) != 0)
		return (0);
	error = redirect(data, str, str + 1);
	if (error)
		return (1);
	if (ft_strncmp(str, "<<", 3) == 0 || ft_strncmp(str, ">>", 3) == 0)
		*str += 1;
	*str += 1;
	return (0);
}

static int	add_argv(t_execution_data *data, char *str)
{
	char	**new_argv;

	new_argv = ft_calloc(data->argc + 1, sizeof(char **));
	if (data->argv)
		ft_memcpy(new_argv, data->argv, data->argc);
	free(data->argv);
	data->argv = new_argv;
	data->argv[data->argc] = ft_strdup(str);
	if (!data->argv[data->argc])
	{
		error(err_alloc_fail);
		return (err_alloc_fail);
	}
	data->argv[data->argc + 1] = NULL;
	return (0);
}

int	execute_single(char **words, int fd_in, int fd_out)
{
	int					error;
	t_execution_data	data;

	init_redirection(&data, fd_in, fd_out);
	while (!is_new_command(*words))
	{
		while (is_redirection(*words))
		{
			error = handle_redirection(&data, words);
			if (error)
				return (error);
		}
		error = add_argv(&data, *words);
		if (error)
			return (error);
	}
}
