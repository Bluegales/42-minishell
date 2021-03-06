/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 06:47:49 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 13:23:25 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_env.h"

#include "environ.h"

int	cmd_env(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	environ_print();
	return (0);
}
