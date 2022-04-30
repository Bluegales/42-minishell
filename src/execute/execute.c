/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 03:49:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 21:38:04 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

#include "execute_data.h"
#include "redirect.h"
#include "libft.h"

int	exec_step(char *str, int *brackets)
{
	int	bracket_count;

	bracket_count = 0;
	if (*str == '(')
		bracket_count++;
	if (*str == ')')
		bracket_count--;
}

int	is_new_command(char *str)
{
	if (ft_strncmp(str, "|", 2) == 0)
		return (1);
	if (ft_strncmp(str, "&", 2) == 0)
		return (1);
	if (ft_strncmp(str, "||", 3) == 0)
		return (1);
	if (ft_strncmp(str, "&&", 3) == 0)
		return (1);
	return (0);
}

int	handle_redirection(t_execute_data *data, char ***str)
{
	int	error;

	if (ft_strncmp(str, "<", 1) != 0 && ft_strncmp(str, ">", 1) != 0)
		return (0);
	error = redirect(data, str, str + 1);
	if (error)
		return (1);
	if (ft_strncmp(str, "<<", 3) == 0 || ft_strncmp(str, ">>", 3) == 0)
		*str += 1;
	*str += 1;
	return (0);
}

int	execute(char **words)
{
	int				error;
	t_execute_data	data;
	char			**it;

	while (!is_new_command(words))
	{
		error = handle_redirection(&data, words);
		if (error)
			return (error);
	}
	int	bracket_returns[20];
}
