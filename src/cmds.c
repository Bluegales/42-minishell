/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:07:16 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/24 21:12:18 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"

#include "libft.h"

typedef struct s_command_function_pair
{
	char			*name;
	t_cmd_function	function;
}					t_command_function_pair;

const static t_command_function_pair	g_commands[] = {
{"asd", cmd_export},
{"asd2", cmd_export}
};

t_cmd_function	get_function(char *command)
{
	int	i;

	i = 0;
	while (i < (int)(sizeof(g_commands) / sizeof(g_commands[0])))
	{
		if (ft_strncmp(command, g_commands[i].name, 20) == 0)
			return (g_commands[i].function);
	}
}
