/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:14:53 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/03 19:00:15 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <stdint.h>

typedef struct s_execute_data	t_execute_data;

typedef struct s_logic_data
{
	char	**words;
	int		last_return;
}	t_logic_data;

int	execute(char **words);

#endif // EXECUTE_H
