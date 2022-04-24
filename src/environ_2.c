/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:39:17 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/24 21:34:37 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

extern char	**environ;

void	environ_cleanup(void)
{
	while (*environ)
	{
		free(*environ);
		environ++;
	}
	free(environ);
}

int	environ_init(void)
{
	char	**env;
	char	**it;

	it = environ;
	environ_print();
	env = malloc(sizeof(char *));
	if (*env)
		return (1);
	*env = NULL;
	environ = env;
	while (*it)
	{
		environ_print();
		if (environ_add(*it))
		{
			environ_cleanup();
			return (1);
		}
		it++;
	}
	return (0);
}

void	environ_print(void)
{
	char	**it;

	it = environ;
	while (*it)
	{
		write(1, *it, ft_strlen(*it));
		write(1, "\n", 1);
		it++;
	}
}
