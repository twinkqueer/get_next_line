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

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s++ == (char)c)
			return ((char *)--s);
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
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
	char	*newline;
	int		line_len;
	char	*line;
	int		i;

	i = 0;
	newline = ft_strchr(buffer, '\n');
	if (newline)
		line_len = newline - buffer + 1;
	else
		line_len = ft_strlen(buffer);
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	while (i < line_len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_buffer(char *buffer)
{
	char	*newline;
	char	*dupe;
	char	*duped;
	int		i;
	
	i = 0;
	newline = ft_strchr(buffer, '\n');
	if (!newline || !*(newline + 1))
		return (free(buffer), NULL);
	dupe = newline + 1;
	duped = malloc(sizeof(char) * ft_strlen(dupe) + 1);
	if (!duped)
		return (free(buffer), NULL);
	while(i < ft_strlen(dupe))
	{
		duped[i] = dupe[i];
		i++;
	}
	duped[i] = '\0';
	free(buffer);
	return (duped);
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


