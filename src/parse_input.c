/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:36:04 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/25 01:59:19 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cmds.h"

static int parse_section(char *str)
{

}

static int	create_pipe()
{

}

enum e_escape {esc_none = 0, esc_single = 1, esc_double = 2};

typedef struct s_parse_data
{
	enum e_escape	escape;
	int				priority;
}	t_parse_data;

static int handle_escape(char *str, t_parse_data *data)
{
	if (*str == '\'')
	{
		if (data->escape == esc_single)
			data->escape = esc_none;
		else
			data->escape = esc_single;
		return (1);
	}
	if (*str == '"')
	{
		if (data->escape == esc_double)
			data->escape = esc_none;
		else
			data->escape = esc_double;
		return (1);
	}
	return (0);
}

typedef struct s_section_data
{
}	t_section_data;

static int	parse_section(char *str, int len)
{

}

int	parse_input(char *str)
{
	t_parse_data	data;
	char	*it;

	ft_memset(&data, 0, sizeof(t_parse_data));
	while (*it)
	{
		if (!data.escape == esc_none)
		{
			if (*it == '|' || *it == '&')
			{
				if (it[1] != '|')

				parse_section();
			}
		}
		it += handle_escape(it, &data);
	}
}
