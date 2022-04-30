/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:24:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 20:11:40 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_DATA_H
# define EXECUTE_DATA_H

typedef struct s_execute_data
{
	int		fd_in;
	int		fd_out;
	int		argc;
	char	**argv;
}	t_execute_data;

int	execute_data_create(char **words, int fd_in, int fd_out);

#endif // EXECUTE_DATA_H
