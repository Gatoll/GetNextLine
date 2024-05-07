/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaokazak <kaokazak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:20:56 by kaokazak          #+#    #+#             */
/*   Updated: 2024/05/08 01:00:32 by kaokazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *cache)
{
	char	*buf;
	char	*tmp;
	int		read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = BUFFER_SIZE;
	while (!ft_strchr(cache, '\n') && read_bytes == BUFFER_SIZE)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1 || (!read_bytes && !cache))
		{
			free(cache);
			cache = NULL;
			return (free(buf), NULL);
		}
		buf[read_bytes] = '\0';
		if (!cache)
			cache = ft_strdup("");
		tmp = ft_strjoin(cache, buf);
		free(cache);
		cache = tmp;
	}
	return (free(buf), cache);
}

static char	*ft_get_line(char *cache, int *linelen)
{
	char	*line;
	int		i;

	if (!cache || cache[0] == '\0')
		return (NULL);
	*linelen = ft_linelen(cache);
	if (!(ft_strchr(cache, '\n')))
		line = (char *)malloc(sizeof(char) * (*linelen + 1));
	else
		line = (char *)malloc(sizeof(char) * (*linelen + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (i < *linelen)
	{
		line[i] = cache[i];
		i++;
	}
	if (cache[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_save(char *cache, int linelen)
{
	char	*res;
	int		i;

	if (!cache)
		return (NULL);
	if (cache[linelen] != '\n')
	{
		free(cache);
		cache = NULL;
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(&cache[linelen + 1]) + 1));
	if (!res)
	{
		free(cache);
		cache = NULL;
		return (NULL);
	}
	linelen++;
	i = 0;
	while (cache[linelen] != '\0')
		res[i++] = cache[linelen++];
	res[i] = '\0';
	return (free(cache), res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cache;
	int			linelen;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cache = ft_read(fd, cache);
	if (!cache)
		return (NULL);
	line = ft_get_line(cache, &linelen);
	if (!line)
	{
		free(cache);
		cache = NULL;
		return (NULL);
	}
	cache = ft_save(cache, linelen);
	return (line);
}
