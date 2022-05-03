/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 07:41:48 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 19:06:10 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

#include <stdio.h>

#include "execute_data.h"
#include "builtin.h"
#include "error.h"

int	execute_builtin(t_execute_data *data)
{
	if (!data->builtin)
	{
		fprintf(stderr, "builtin is NULL\n");
		return (1);
	}
	data->builtin(data->argc, data->argv);
	return (0);
}
