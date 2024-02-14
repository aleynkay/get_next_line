/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akay <akay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:25:31 by akay              #+#    #+#             */
/*   Updated: 2024/02/05 18:17:11 by akay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(char *str, int fd)
{
	char	*line;
	int		i;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	i = 1;
	while (ft_strchr(str, '\n') == 0 && i != 0)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			free(line);
			return (0);
		}
		line[i] = '\0';
		str = ft_strjoin(str, line);
	}
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[10000];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str[fd] = read_line(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = read_first_line(str[fd]);
	str[fd] = next_read(str[fd]);
	return (line);
}
