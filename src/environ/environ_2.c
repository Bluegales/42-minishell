/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:39:17 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/25 01:59:22 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

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
	char	**it;

	it = environ;
	//printf("it: %p, environ: %pn\n", it, environ);
	environ = malloc(sizeof(char *));
	if (!environ)
		return (1);
	*environ = NULL;
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
