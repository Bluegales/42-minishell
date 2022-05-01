/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:23:02 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/01 08:02:30 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <readline/readline.h>
#include <stdlib.h>

#include "environ.h"
#include "parse.h"
#include "libft.h"
#include "cmds.h"
#include "execute.h"

extern char **environ;

static const char promt[] = { 0xE2, 0x9E, 0x9C, ' ', '\0'};

int	minishell()
{
	char			*buf;
	char			**words;
	//t_cmd_function	command_function;

	if (environ_init())
		return (1);
	while (1)
	{
		buf = readline(promt);
		add_history(buf);

		if (ft_strncmp(buf, "exit", 4) == 0)
		{
			free(buf);
			//rl_clear_history();
			environ_cleanup();
			return (0);
		}
		words = parse(buf);
		execute(words);

		free(buf);
		//command_function = get_function(buf);
		//printf("got %p", command_function);
		// if (command_function)
		// 	command_function(buf);
	}
	return (0);
}
