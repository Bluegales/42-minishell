/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:17:20 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 17:06:11 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

#include "libft.h"

// enum e_error {
// 	e_alloc_fail = 1,
// 	e_parse = 2
// };

static const char	*g_error_msg[] = {
	"error: important allocation failed\n",
	"error: parsing failed",
};

void	error(enum e_error error)
{
	write(2, g_error_msg[error], ft_strlen(g_error_msg[error]));
	//exit(error);
}
