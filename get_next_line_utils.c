/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jans <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:09:44 by jans              #+#    #+#             */
/*   Updated: 2024/10/11 09:49:56 by jsekne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_strjoin(char **s1, char const *s2)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc((str_length(*s1, s2) + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (*(*s1))
		arr[i++] = *(*s1)++;
	while (*s2)
		arr[i++] = *s2++;
	arr[i] = '\0';
	return (arr);
}

int	str_length(const char *s1, const char *s2)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s1[i])
		i++;
	while (s2[len])
		len++;
	return (i + len);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*orig;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	orig = str;
	while (s[start] && len-- > 0)
		*str++ = s[start++];
	*str = '\0';
	return (orig);
}
