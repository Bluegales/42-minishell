/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:02:14 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 07:33:08 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

#include "cmds.h"
#include "libft.h"

typedef struct s_command_function_pair
{
	char			*name;
	t_builtin_main	function;
}	t_command_function_pair;

static const t_command_function_pair	g_commands[] = {
	{"cd", cmd_cd},
	{"echo", cmd_echo},
	{"env", cmd_env},
	{"export", cmd_export},
	{"pwd", cmd_pwd},
	{"unset", cmd_unset}
};

t_builtin_main	get_builtin(char *command)
{
	int	i;

	i = 0;
	while (i < (int)(sizeof(g_commands) / sizeof(g_commands[0])))
	{
		if (ft_strncmp(command, g_commands[i].name, 20) == 0)
			return (g_commands[i].function);
		i++;
	}
	return (NULL);
}
