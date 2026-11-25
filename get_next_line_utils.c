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
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < line_len)
		line[i] = buffer[i];
	line[i] = '\0';
	free(buffer);
	return (line);
}

void	shift(char *buffer)
{
	size_t	i;
	size_t	shift;

	shift = newline_pos(buffer);
	i = 0;
	if (shift == (size_t)-1)
	{
		while (buffer[i])
		{
			buffer[i] = 0;
			i++;
		}
		return ;
	}
	while (buffer[shift + i + 1])
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
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (free(s1), shift(s2), res);
}
