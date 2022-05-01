/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:24:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/01 18:51:49 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_DATA_H
# define EXECUTE_DATA_H

typedef struct s_execute_data
{
	int		fd_in;
	char	*file_in;
	int		file_in_flags;

	int		fd_out;
	char	*file_out;
	int		file_out_flags;

	int		argc;
	char	**argv;
	char	*executable;

	char	**paths;
}	t_execute_data;

int	execute_data_create(t_execute_data *data, char ***words);
#endif // EXECUTE_DATA_H
