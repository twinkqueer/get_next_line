/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpankrat <mpankrat@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:16:48 by mpankrat          #+#    #+#             */
/*   Updated: 2026/11/07 16:31:15 by mpankrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*stash;
	char			*line;
	ssize_t			ft_read;

	ft_read = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n') && ft_read > 0)
	{
		ft_read = read(fd, buffer, BUFFER_SIZE);
		if (ft_read < 0)
			return (free(buffer), NULL);
		buffer[ft_read] = '\0';
		if (ft_read == 0)
			return (NULL);
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	line = extract(stash);
	if (stash)
		stash = update_buffer(stash);
	return (line);
}
/*
int	main(void)
{
	int		ft_open;
	int		i;
	char	*line;

	i = 0;
	ft_open = open("open.txt", O_RDONLY);
	while (i < 7)
	{
		line = get_next_line(ft_open);
		if (!line)
			break ;
		printf("GNL %d: %s\n", i, line);
		free(line);
		i++;
	}
	close(ft_open);
	return (0);
}
*/
