/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 05:44:22 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 05:35:42 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "words_util.h"

#include "libft.h"

int	is_logic_connector(char *str)
{
	if (ft_strncmp("||", str, 3) == 0)
		return (1);
	if (ft_strncmp("&&", str, 3) == 0)
		return (1);
	return (0);
}

int	is_redirection(char *str)
{
	if (!str)
		return 0;
	if (*str == '<')
		return (1);
	if (*str == '>')
		return (1);
	return (0);
}

int	is_command_connector(char *str)
{
	if (ft_strncmp("||", str, 3) == 0)
		return (1);
	if (ft_strncmp("&&", str, 3) == 0)
		return (1);
	if (ft_strncmp("|", str, 2) == 0)
		return (1);
	return (0);
}

int	is_command(char *str)
{
	if (ft_strncmp("||", str, 3) == 0)
		return (0);
	if (ft_strncmp("&&", str, 3) == 0)
		return (0);
	if (ft_strncmp("|", str, 2) == 0)
		return (0);
	if (*str == ')')
		return (0);
	return (1);
}

int	is_new_command(char *str)
{
	if (*str == '<')
		return (1);
	if (*str == '>')
		return (1);
	if (*str == '|')
		return (1);
	if (*str == '&')
		return (1);
	return (0);
}

int	is_pipe(char *str)
{
	if (ft_strncmp("||", str, 3) == 0)
		return (0);
	if (ft_strncmp("&&", str, 3) == 0)
		return (0);
	if (*str == ')')
		return (0);
	return (1);
}
