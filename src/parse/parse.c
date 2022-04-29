/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:36:04 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/29 08:24:11 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "parse_vars.h"

#include <stdio.h>

int	parse(char **str)
{
	int		error;

	error = parse_vars(str);
	printf("%s", *str);
	return (error);
}
