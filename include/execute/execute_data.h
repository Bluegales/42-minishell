/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:24:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 07:34:13 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_DATA_H
# define EXECUTE_DATA_H

# include <limits.h>
# include "builtin.h"

typedef struct s_execute_data
{
	int		fd_in;
	char	*file_in;
	int		file_in_flags;

	int		fd_out;
	char	*file_out;
	int		file_out_flags;

	t_builtin_main	builtin;
	int		argc;
	char	**argv;
	char	*executable;

	char	command_path[PATH_MAX];
}	t_execute_data;

int		execute_data_create(t_execute_data *data, char ***words);
void	execute_data_cleanup(t_execute_data *data);
void	execute_data_cleanup_multi(t_execute_data *data, int count);
#endif // EXECUTE_DATA_H
