/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_data.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:24:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 17:56:24 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_DATA_H
# define EXECUTION_DATA_H

typedef struct s_execution_data
{
	int		fd_in;
	int		fd_out;
	int		argc;
	char	**argv;
}	t_execution_data;


#endif // EXECUTION_DATA_H
