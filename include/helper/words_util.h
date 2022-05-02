/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 06:59:45 by pfuchs            #+#    #+#             */
/*   Updated: 2022/05/02 04:33:00 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDS_UTIL_H
# define WORDS_UTIL_H

int	is_logic_connector(char *str);
int	is_redirection(char *str);
int	is_command_connector(char *str);
int	is_command(char *str);
int	is_new_command(char *str);
int	is_pipe(char *str);

#endif // WORDS_UTIL_H
