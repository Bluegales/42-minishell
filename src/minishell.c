/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:23:02 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/24 02:34:13 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <readline/readline.h>

#include "environ.h"
#include "libft.h"

static const char promt[] = { 0xE2, 0x9E, 0x9C, ' ', '\0'};

int	minishell()
{
	t_environ	env;
	char		*buf;

	environ_init(&env);
	environ_remove(&env, "_");
	environ_add(&env, "ZZZ", "trololo");
	//environ_remove(&env, "TERM");


	environ_debug_print(&env);
	while (1)
	{
		buf = readline(promt);
		add_history(buf);

		if (ft_strncmp(buf, "exit", 4) == 0)
			return (0);
	}
	return (0);
}
