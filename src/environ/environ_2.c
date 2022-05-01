/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:39:17 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/01 18:57:44 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

extern char	**environ;
char		**g_environ;

void	environ_cleanup(void)
{
	char	**it;

	it = g_environ;
	while (*it)
	{
		free(*it);
		*it = NULL;
		it++;
	}
	free(g_environ);
	//g_environ = NULL;
}

int	environ_init(void)
{
	char	**it;

	it = environ;
	//printf("it: %p, environ: %pn\n", it, environ);
	g_environ = malloc(sizeof(char *));
	if (!g_environ)
		return (1);
	*g_environ = NULL;
	while (*it)
	{
		//printf("adding %s\n", *it);
		if (environ_add(*it))
		{
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
