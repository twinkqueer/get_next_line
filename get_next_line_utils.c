/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:52:31 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/11 13:52:46 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	newline_pos(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (-2);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*extract(char *buffer)
{
	ssize_t	newline;
	int		line_len;
	char	*line;
	int		i;

	newline = newline_pos(buffer);
	line_len = ft_strlen(buffer);
	if (newline > -1)
		line_len = newline + 1;
	if (newline == -1)
		line_len = ft_strlen(buffer);
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < line_len)
		line[i] = buffer[i];
	line[i] = '\0';
//	printf("Extracted line: [%s]", line);
	return (line);
}

void	shift(char *buffer)
{
	ssize_t	i;
	ssize_t	shift;

	shift = newline_pos(buffer);
	i = 0;
	if (shift == -1) // if it doesn't find a newline, wipe the entire buffer so it can be refilled
	{	
		while (buffer[i]) {
			buffer[i] = 0;
			i++;
		}	
		return ;
	}
	while (buffer[shift + i + 1]) // otherwise shift it
	{
		buffer[i] = buffer[shift + i + 1];
		i++;
	}
	buffer[i] = buffer[shift + i + 1];
	buffer[i++] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while(j < ft_strlen(s2))
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}


