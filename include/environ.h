/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:52:50 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/24 02:43:26 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H

typedef char	**t_environ;

int		environ_init(t_environ *env);
void	environ_cleanup(t_environ *env);
int		environ_set_size(t_environ *env, int allocated_size);
int		environ_add(t_environ *env, char *str);
int		environ_remove(t_environ *env, char *str);

void	environ_debug_print(t_environ *env);

#endif // ENVIRON_H
