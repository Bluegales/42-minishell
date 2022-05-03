/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_data2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:04:17 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 19:00:28 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_DATA2_H
#define EXECUTE_DATA2_H

# include "execute_data.h"

int		is_new_command(char *str);
int		is_redirection(char *str);
void	execute_data_cleanup(t_execute_data *data);
void	execute_data_init(t_execute_data *data, int fd_in, int fd_out);
void	debug_execution_data(t_execute_data *data);

#endif // EXECUTE_DATA2_H
