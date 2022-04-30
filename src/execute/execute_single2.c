/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:04:06 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 18:04:07 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_redirection(char *str)
{
	if (*str == '<')
		return (1);
	if (*str == '>')
		return (1);
	return (0);
}
