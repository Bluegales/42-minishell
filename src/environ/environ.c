/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:52:53 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/29 10:32:43 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

#include <stdlib.h>

#include "libft.h"

#include <stdio.h>

static int	key_comp(char *key1, char *key2)
{
	//printf("%s, %s\n", key1, key2);
	while (*key1 && *key2 && *key1 != '=')
	{
		if (*key1 != *key2)
		{
			return (*key1 - *key2);
		}
		key1++;
		key2++;
	}
	if (*key1 == '\0' || *key2 == '\0')
		if (*key1 == '=' || *key2 == '=')
			return (0);
	return (*key1 - *key2);
}

// Extension of environ_add
static int	environ_add_copy(char **old, char *new)
{
	char	*new_entry;

	new_entry = ft_strdup(new);
	if (!new_entry)
		return (1);
	free(*old);
	*old = new_entry;

	return (0);
}

int	environ_add(char *new_entry)
{
	char	**new_env;
	int		size;
	char	**old;

	old = NULL;
	size = 0;
	while (environ[size] != NULL)
	{
		if (key_comp(environ[size], new_entry) == 0)
			old = environ + size;
		size++;
	}
	if (!old)
	{
		new_env = malloc(sizeof(char **) * (size + 20));
		if (!new_env)
			return (1);
		ft_memcpy(new_env, environ, size * sizeof(char *));
		free(environ);
		environ = new_env;
		old = new_env + size;
		*old = NULL;
		*(old + 1) = NULL;
	}
	return (environ_add_copy(old, new_entry));
}

char	*environ_get(char *entry)
{
	char	**env_it;
	char	*value;

	env_it = environ;
	while (*env_it)
	{
		if (key_comp(*env_it, entry) == 0)
			break ;
		env_it++;
	}
	if (!*env_it)
		return (NULL);
	value = *env_it;
	while (*value && *value != '=')
		value++;
	if (*value == '=')
		value++;
	return (value);
}

void	environ_remove(char *entry)
{
	while (*environ)
	{
		if (key_comp(*environ, entry))
			break ;
		environ++;
	}
	if (!*environ)
		return ;
	free(environ);
	free(environ + 1);
	while (*(environ + 1))
	{
		*environ = *(environ + 1);
		environ++;
	}
}