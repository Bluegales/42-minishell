/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:52:53 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/24 03:10:23 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"

#include <stdlib.h>
#include <limits.h>

#include "libft.h"

extern char	**environ;

void	environ_cleanup(t_environ **env)
{
	while (*env)
	{
		free(*env);
		env++;
	}
}

int	environ_init(t_environ ***env)
{
	int		i;
	int		error;

	*env = malloc(sizeof(char *));
	if (*env)
		return (1);
	while (*environ)
	{
		if (environ_add(env, environ[i]))
		{
			environ_cleanup(env);
			return (1);
		}
	}
	return (0);
}

t_environ	**environ_add(t_environ **env, char *str)
{
	t_environ	***new_env;
	int	i;

	//environ_remove(env, key);
	i = 0;
	while (*env)
		i++;
	new_env = malloc(sizeof(char **) * (i + 1));
	ft_memcpy(new_env, *env)

	error = 0;
	if (i == env->allocated_size - 1)
		error = environ_set_size(env, i + 16);
	if (error)
		return (error);
	env->pairs[i].key = ft_strdup(str);
	env->pairs[i].value = ft_strdup(value);
	env->pairs[i + 1].key = NULL;
	return (0);
}

// int	environ_remove(t_environ *env, char *key)
// {
// 	int	i;
// 	int	error;

// 	i = 0;
// 	while (i < env->allocated_size)
// 	{
// 		if (env->pairs[i].key)
// 		{
// 			if (ft_strncmp(env->pairs[i].key, key, INT_MAX) == 0)
// 			{
// 				free(env->pairs[i].key);
// 				env->pairs[i].key = NULL;
// 				return (0);
// 			}
// 		}
// 		i++;
// 	}
// 	return (1);
// }

#include <stdio.h>

void	environ_debug_print(t_environ *env)
{
	int	i;

	printf("real env:\n");
	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	printf("\n\n\nfake env:\n");
	i = 0;
	while (i < env->allocated_size)
	{
		if (env->pairs[i].key)
			printf("%s=%s\n", env->pairs[i].key, env->pairs[i].value);
		else
			printf("---\n");
		i++;
	}
}
