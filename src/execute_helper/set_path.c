/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:08:28 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 12:19:29 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h> // PATH_MAX

#include <unistd.h>
#include <stdio.h>

#include <semaphore.h>

#include "execute_data.h"
#include "environ.h"
#include "error.h"
#include "libft.h"

static int	find_correct_path(t_execute_data *data, char **split)
{
	if (ft_strchr(data->argv[0], '/'))
	{
		ft_strlcat(data->command_path, data->argv[0], PATH_MAX - 1);
		if (access(data->command_path, X_OK) == 0)
			return (0);
		perror(data->argv[0]);
		return (1);
	}
	while (*split)
	{
		ft_strlcpy(data->command_path, *split, PATH_MAX - 1);
		ft_strlcat(data->command_path, "/", PATH_MAX - 1);
		ft_strlcat(data->command_path, data->argv[0], PATH_MAX - 1);
		if (access(data->command_path, X_OK) == 0)
			return (0);
		split++;
	}
	perror(data->argv[0]);
	return (1);
}

int	set_command_path(t_execute_data *data)
{
	char	*paths;
	char	**split;

	if (data->builtin)
		return (0);
	paths = environ_get("PATH");
	if (paths)
	{
		split = ft_strsplit(paths, ':');
		if (!split)
			return (error_msg(err_alloc_fail));
		find_correct_path(data, split);
		ft_free_pointer_array((void **)split);
	}
	return (0);
}
