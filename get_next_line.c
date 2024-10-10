/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jans <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:09:24 by jans              #+#    #+#             */
/*   Updated: 2024/10/10 09:10:28 by jans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE = 10;

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*newline;

	if (fd == -1)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = write_to_buffer(fd, buffer, line);
	set_newline(line, newline);
	return (newline);
}

char	*set_newline(char *line, char *newline)
{
	// go through the stinrg until you find delimiter
	// set \0 and store that string to newline
	// store the rest to line
	return (newline);
}

char	*write_to_buffer(int fd, char *buffer, char *line)
{
	while (read(fd, buffer, BUFFER_SIZE))
	{
		if (ft_strlen(line) == 0)
			line = ft_strdup(buffer);
		else
			ft_strjoin(old, buffer);
		if (contains_delimiter(buffer))
			break ;
	}
	return (old);
}

int	contains_delimiter(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (1);
	}
	return (0);
}
