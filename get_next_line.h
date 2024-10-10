/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jans <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:10:03 by jans              #+#    #+#             */
/*   Updated: 2024/10/10 08:58:38 by jans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *s);
int		contains_delimiter(char *str);
int		str_length(const char *s1, const char *s2);
char	*write_to_buffer(int fd, char *buffer, char *line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
#endif
