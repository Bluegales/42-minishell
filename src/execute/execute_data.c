/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 03:49:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/01 09:12:35 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_data.h"

#include <stdlib.h> // free

#include "execute_data2.h"
#include "words_util.h"
#include "error.h"
#include "redirect.h"
#include "libft.h"

static int	handle_redirection(t_execute_data *data, char ***str)
{
	int	error;

	if (***str != '>' && ***str != '<')
		return (0);
	error = redirect(data, **str, **str + 1);
	if (error)
		return (1);
	if (ft_strncmp(**str, "<<", 3) == 0 || ft_strncmp(**str, ">>", 3) == 0)
		*str += 1;
	*str += 1;
	return (0);
}

static int	add_argv(t_execute_data *data, char *str)
{
	char	**new_argv;

	new_argv = ft_calloc(data->argc + 2, sizeof(char **));
	if (!new_argv)
	{
		error(err_alloc_fail);
		return (err_alloc_fail);
	}
	if (data->argv)
		ft_memcpy(new_argv, data->argv, data->argc * sizeof(char *));
	free(data->argv);
	data->argv = new_argv;
	data->argv[data->argc] = ft_strdup(str);
	if (!data->argv[data->argc])
	{
		error(err_alloc_fail);
		return (err_alloc_fail);
	}
	data->argv[data->argc + 1] = NULL;
	data->argc++;
	return (0);
}

int	execute_data_create(t_execute_data *data ,char **words)
{
	int				error;

	execute_data_init(&data, 0, 1);
	while (*words && !is_logic_connector(*words))
	{
		while (is_redirection(*words))
		{
			error = handle_redirection(&data, &words);
			if (error)
			{
				execute_data_cleanup(&data);
				return (error);
			}
		}
		error = add_argv(&data, *words);
		if (error)
		{
			execute_data_cleanup(&data);
			return (error);
		}
		words++;
	}
	debug_execution_data(&data);
	return (0);
}
