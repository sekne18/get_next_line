/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jans <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:35:41 by jans              #+#    #+#             */
/*   Updated: 2024/10/11 09:10:02 by jsekne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (*(line = get_next_line(fd)) != '\0')
	{
		printf("%s", line);
	}
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
