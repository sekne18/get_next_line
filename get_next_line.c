/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jans <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:09:24 by jans              #+#    #+#             */
/*   Updated: 2024/10/11 17:04:32 by jsekne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*newline;

	if (fd == -1)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	if (line == NULL || !contains_delimiter(line, "\n"))
		write_to_buffer(fd, buffer, &line);
	free(buffer);
	if (!line)
		return (NULL);		
	cut_newline(&line, &newline);
	return (newline);
}

void	cut_newline(char **line, char **newline)
{
	size_t		i;

	i = 0;
	while ((*line)[i] != '\n' && (*line)[i] != '\0')
		i++;
	if ((*line)[i] == '\n')
		i++;
	*newline = ft_substr(*line, 0, i);
	*line = ft_substr(*line, i, ft_strlen((const char*) *line) - i);
	if (ft_strlen(*line) == 0)
	{
		free(*line);
		*line = NULL;
	}
}

void	write_to_buffer(int fd, char *buffer, char **line)
{
	int	bytes_read;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (*line == NULL || ft_strlen(*line) == 0)
			*line = ft_substr(buffer, 0, bytes_read);
		else
			*line = ft_strjoin(*line, ft_substr(buffer, 0, bytes_read));
		if (contains_delimiter(buffer, "\n\0"))
			break ;
	}
}

int	contains_delimiter(char *line, char *d)
{
	int		i;
	char	*dlm;

	i = -1;
	while (line[++i])
	{
		dlm = d;
		while (*dlm)
		{	
			if (line[i] == *dlm++)
				return (1);
		}
	}
	return (0);
}
