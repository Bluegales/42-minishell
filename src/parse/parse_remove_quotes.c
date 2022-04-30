/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_remove_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 02:26:41 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 15:15:42 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// void	parse_remove_quotes(char *str)
// {
// 	int		quote;
// 	char	*str_replace;

// 	quote = 0;
// 	str_replace = str;
// 	while (*str)
// 	{
// 		*str_replace = *str;
// 		if (*str == '\'')
// 			quote = 1 - quote;
// 		else if (quote || *str != '"')
// 			str_replace++;
// 		str++;
// 	}
// 	*str_replace = '\0';
// }

void	parse_remove_quotes(char *str)
{
	int		quote;
	int		length;

	quote = *str;
	length = ft_strlen(str);
	if (quote != '\'' && quote != '\"')
		return ;
	ft_memmove(str, str + 1, length);
	if (str[length - 2] == quote)
		str[length - 2] = '\0';
}
