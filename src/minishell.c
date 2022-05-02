/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:23:02 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 06:35:49 by pfuchs           ###   ########.fr       */
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

	if (environ_init())
		return (1);
	while (1)
	{
		buf = readline(promt);
		add_history(buf);
		if (!buf)
			continue;
		if (ft_strncmp(buf, "exit", 4) == 0)
		{
			free(buf);
			rl_clear_history();
			environ_cleanup();
			return (0);
		}
		words = parse(buf);
		printf("now executing\n");
		if (*words != NULL)
			execute(words);
		int i = 0;
		while (words[i])
		{
			free(words[i]);
			i++;
		}
		free(words);
		free(buf);
	}
	return (0);
}
