/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 06:47:49 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 08:25:00 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_unset.h"

#include "environ.h"

int	cmd_unset(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		environ_remove(argv[i]);
		i++;
	}
	return (0);
}
