/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:19:01 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 17:05:14 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_ALLOC_FAIL 1

enum e_error {
	err_alloc_fail = 1,
	err_parse = 2,
};

void	error(enum e_error error);

#endif // ERROR_H
