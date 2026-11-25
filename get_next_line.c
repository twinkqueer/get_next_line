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
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	char			*extracted;
	ssize_t			read_val;

	read_val = 1;
	line = NULL;
	extracted = NULL;
	if (buffer[0] == 0)
		read_val = read(fd, buffer, BUFFER_SIZE);
	while (read_val > 0)
	{
		if (newline_pos(buffer) != (size_t)-1)
		{
		//	printf("[ newline pos is over -1 (found newline) ]\n");
			line = ft_strjoin(line, buffer);
		//	printf("[ FOUND NEWLINE: strjoined line: %s ]\n", line);
			extracted = extract(line);
		//	printf("[ FOUND NEWLINE: extracted line: %s ]\n", extracted);
			free(line);
			shift(buffer);
			return(extracted);
		}
		else
		{
		//	printf("[ current newline pos: %ld (this only calls if its supposedly -1) ]\n", newline_pos(buffer));
			if (read_val == BUFFER_SIZE)
			{
		//		printf("[ -1 nl: read_val is equal to buffer size ]\n");
				line = ft_strjoin(line, buffer);
		//		printf("[ -1 nl: joined line: %s ]\n", line);
				shift(buffer);
			}
		}
	   	read_val = read(fd, buffer, BUFFER_SIZE);
	   	if (read_val == 0)
	   	{
	   	//	printf("read_val is 0");
			return (line);
	   	}
		if (read_val < 0)
			return (free(line), NULL);
	}
	return (NULL);
}
#include <stdlib.h>
int	main(int argc, char *arg[])
{
	int		ft_open;
	int		i;
	char	*line;

	(void)argc;
	i = 0;
	ft_open = open(arg[1], O_RDONLY);
	while (i < atoi(arg[2]))
	{
		line = get_next_line(ft_open);
		if (!line)
			return 0;
		printf(" | GNL %d: %s", i + 1, line);
		free(line);
		i++;
	}
	close(ft_open);
	return (0);
}
