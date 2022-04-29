/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:23:02 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/29 10:34:50 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <readline/readline.h>

#include "environ.h"
#include "parse.h"
#include "libft.h"
#include "cmds.h"

static const char promt[] = { 0xE2, 0x9E, 0x9C, ' ', '\0'};

int	minishell()
{
	char			*buf;
	t_cmd_function	command_function;

	if (environ_init())
		return (1);
	while (1)
	{
		buf = readline(promt);
		add_history(buf);

		if (ft_strncmp(buf, "exit", 4) == 0)
			return (0);
		parse(&buf);
		//command_function = get_function(buf);
		//printf("got %p", command_function);
		// if (command_function)
		// 	command_function(buf);
	}
	return (0);
}
