/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_remove_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 02:26:41 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 02:54:11 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	parse_remove_quotes(char *str)
{
	int		quote;
	char	*str_replace;

	quote = 0;
	str_replace = str;
	while (*str)
	{
		*str_replace = *str;
		if (*str == '\'')
			quote = 1 - quote;
		else if (quote || *str != '"')
			str_replace++;
		str++;
	}
	*str_replace = '\0';
}
