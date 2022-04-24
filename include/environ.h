/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:52:50 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/24 22:21:37 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H

extern char	**environ;

int		environ_init(void);
void	environ_cleanup(void);
int		environ_add(char *new_entry);
void	environ_remove(char *entry);

void	environ_print(void);

#endif // ENVIRON_H
