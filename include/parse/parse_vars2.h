/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vars2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 05:33:04 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/29 07:44:59 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_VARS2_H
# define PARSE_VARS2_H

// static functions that fonud no space in their .c files...
int	cleanup(char **pieces, int error_return);
int	count_vars(const char *str);

#endif // PARSE_VARS2_H
