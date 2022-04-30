/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 03:49:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 03:52:35 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	exec_step(char *str, int *brackets)
{
	int	bracket_count;

	bracket_count = 0;
	if (*str == '(')
		bracket_count++;
	if (*str == ')')
		bracket_count--;


}


int	execute(char *str)
{
	int	brackets[20];


}
