/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:08:28 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/01 19:14:10 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h> // PATH_MAX

#include "is_builtin.h"
#include "execute_data.h"
#include "environ.h"
#include "error.h"

static int	find_correct_path(t_execute_data *data, char **split)
{
	while (*split)
	{
		ft_strlcpy(child->path_cmd, pipex_data->paths[i], PATH_MAX - 1);
		ft_strlcat(child->path_cmd, "/", PATH_MAX - 1);
		ft_strlcat(child->path_cmd, child->cmd, PATH_MAX - 1);
		if (access(child->path_cmd, X_OK) == 0)
			return (0);
	}
}

int	set_command_path(t_execute_data *data)
{
	char	command_path[PATH_MAX];
	char	*paths;
	char	**split;

	if (is_builtin(data->argv[0]))
	{
		return (0);
	}
	paths = environ_get("PATH");
	if (!paths)
		return (error(err_alloc_fail));
	split = ft_strsplit(paths, ':');
	if (!split)
		return (error(err_alloc_fail));
	return (find_correct_path(data, split));
}
