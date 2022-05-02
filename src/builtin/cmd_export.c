/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 06:47:49 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 08:23:31 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_export.h"

#include "environ.h"

int	cmd_export(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		environ_add(argv[i]);
		i++;
	}
}
