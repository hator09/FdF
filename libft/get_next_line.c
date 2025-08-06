/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:32:13 by martisan          #+#    #+#             */
/*   Updated: 2025/05/26 18:48:28 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	contains_newline(char *stored)
{
	if (!stored)
		return (0);
	while (*stored)
	{
		if (*stored == '\n')
			return (1);
		stored++;
	}
	return (0);
}

static char	*read_buffer_size(int fd, char *stored)
{
	char	*buffer;
	int		readbytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(stored);
		return (NULL);
	}
	readbytes = 1;
	while (!contains_newline(stored) && readbytes != 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if ((!stored && readbytes <= 0) || readbytes == -1)
		{
			free(buffer);
			free(stored);
			return (NULL);
		}
		buffer[readbytes] = '\0';
		stored = f_strjoin(stored, buffer);
	}
	free(buffer);
	return (stored);
}

static char	*extract_line(char *stored)
{
	size_t	i;

	i = 0;
	if (!stored || stored[0] == '\0')
		return (NULL);
	while (stored[i] != '\n' && stored[i])
		i++;
	if (stored[i] == '\n')
		i++;
	return (f_substr(stored, 0, i));
}

static char	*update_stored(char *stored)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	*new;

	i = 0;
	len = 0;
	if (!stored[i])
	{
		free(stored);
		return (NULL);
	}
	while (stored[i] != '\n' && stored[i])
		i++;
	if (stored[i] == '\n')
		i++;
	start = i;
	while (stored[i])
	{
		i++;
		len++;
	}
	new = f_substr(stored, start, len);
	free(stored);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stored;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stored);
		return (0);
	}
	stored = read_buffer_size(fd, stored);
	if (!stored)
		return (NULL);
	line = extract_line(stored);
	stored = update_stored(stored);
	return (line);
}
