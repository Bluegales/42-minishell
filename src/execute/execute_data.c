/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 03:49:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 10:32:17 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_data.h"

#include <stdlib.h> // free

#include "execute_data2.h"
#include "words_util.h"
#include "error.h"
#include "redirect.h"
#include "libft.h"
#include "environ.h"
#include "builtin.h"

static int	handle_redirection(t_execute_data *data, char ***str)
{
	int	error;

	if (***str != '>' && ***str != '<')
		return (0);
	error = redirect(data, **str, **str + 1);
	if (error)
		return (1);
	//if (ft_strncmp(**str, "<<", 3) == 0 || ft_strncmp(**str, ">>", 3) == 0)
	//	*str += 1;
	*str += 2;
	return (0);
}

static void	remove_quotes(char *str)
{
	char	quote;

	while (*str && *str != '\'' && *str != '\"')
		str++;
	if (!*str)
		return ;
	quote = *str;
	ft_memmove(str, str + 1, ft_strlen(str));
	while (*str && *str != quote)
		str++;
	if (!*str)
		return ;
	ft_memmove(str, str + 1, ft_strlen(str));
	remove_quotes(str);
}

static int	add_argv(t_execute_data *data, char *str)
{
	char	**new_argv;

	new_argv = ft_calloc(data->argc + 2, sizeof(char **));
	if (!new_argv)
		return (error_msg(err_alloc_fail));
	if (data->argv)
		ft_memcpy(new_argv, data->argv, data->argc * sizeof(char *));
	free(data->argv);
	data->argv = new_argv;
	data->argv[data->argc] = ft_strdup(str);
	remove_quotes(data->argv[data->argc]);
	if (!data->argv[data->argc])
		return (error_msg(err_alloc_fail));
	data->argv[data->argc + 1] = NULL;
	data->argc++;
	return (0);
}

int	execute_data_create(t_execute_data *data, char ***words)
{
	int		error;

	execute_data_init(data, 0, 1);
	while (**words && is_command(**words))
	{
		while (**words && is_redirection(**words))
		{
			error = handle_redirection(data, words);
			if (error)
			{
				execute_data_cleanup(data);
				return (error);
			}
		}
		if (!**words)
			break;
		error = add_argv(data, **words);
		if (error)
		{
			execute_data_cleanup(data);
			return (error);
		}
		*words += 1;
	}
	data->builtin = get_builtin(data->argv[0]);
	debug_execution_data(data);
	return (0);
}
