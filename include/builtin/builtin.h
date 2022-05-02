/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:02:44 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 07:32:16 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_BUILTIN_H
# define IS_BUILTIN_H

typedef int	(*t_builtin_main)(int, char **);

t_builtin_main	get_builtin(char *command);

#endif // IS_BUILTIN_H
