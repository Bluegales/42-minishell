/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 06:47:49 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 15:10:19 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_cd.h"

#include <unistd.h> // chdir
#include <stdio.h> // perror

#include "error.h"
#include "environ.h" // HOME

int	cmd_cd(int argc, char **argv)
{
	char	*home;
	int		error;

	if (argc > 2)
		return (error_msg(err_manny_arguments));
	if (argc == 1)
	{
		home = environ_get("HOME");
		printf("home is: -%s-", home);
		if (!home || *home == '\0')
			return (chdir("/"));
		error = chdir(home);
		if (error)
			perror(home);
		return (error);
	}
	error = chdir(argv[1]);
	if (error)
		perror(argv[1]);
	return (error);
}
