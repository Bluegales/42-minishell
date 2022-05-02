/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:19:01 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 08:39:23 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_ALLOC_FAIL 1

static const char error_prefix[] = "minishell: ";

enum e_error {
	err_alloc_fail = 1,
	err_parse = 2,
	err_pipe = 3,
	err_child_back = 4,
	err_command = 5,
	err_manny_arguments = 6
};

int	error_msg(enum e_error error_msg);

#endif // ERROR_H
