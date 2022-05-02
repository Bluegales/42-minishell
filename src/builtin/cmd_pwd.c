/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 06:47:49 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 08:32:53 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_pwd.h"

#include <limits.h> // PATH_MAX
#include <unistd.h> // getcwd
#include <stdio.h> // printf

int	cmd_pwd(int argc, char **argv)
{
	char	cwd[PATH_MAX];

	(void) argc;
	(void) argv;
	cwd[0] = '\0';
	getcwd(cwd, PATH_MAX);
	printf("%s\n", cwd);
	return (0);
}
