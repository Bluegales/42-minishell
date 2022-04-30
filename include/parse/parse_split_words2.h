/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_words2.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:00:07 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/30 10:07:02 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_SPLIT_WORDS2_H
# define PARSE_SPLIT_WORDS2_H

char	*next_split_location(const char *str, const char *delims);
int		split_length(const char *str, const char *delims);
int		count_splits(const char *str, const char *delims);

#endif // PARSE_SPLIT_WORDS2_H
