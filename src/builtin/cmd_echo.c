/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 06:47:49 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 07:38:50 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	cmd_echo(int argc, char **argv)
{
	int	new_line;
	int	i;

	i = 1;
	new_line = 1;
	if (argc > 1 && ft_strncmp("-n", argv[1], 3) == 0)
	{
		new_line = 0;
		i = 2;
	}
	while (i < argc)
	{
		printf("%s", argv[i]);
		i++;
		if (i != argc)
			printf(" ");
	}
	if (new_line)
		printf("\n");
	return (0);
}
