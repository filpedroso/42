/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:56:33 by fpedroso          #+#    #+#             */
/*   Updated: 2024/12/04 15:48:56 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*leftover_collector(char *line);
static char	*linetrim(char *line);
static char	*linefill(char *leftovers, int fd);
static char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*line;

	if (!leftovers)
		leftovers = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		nulfree(&leftovers);
		return (NULL);
	}
	line = linefill(leftovers, fd);
	nulfree(&leftovers);
	if (!line)
		return (NULL);
	leftovers = leftover_collector(line);
	line = linetrim(line);
	if (!line)
		nulfree(&leftovers);
	return (line);
}

static char	*leftover_collector(char *line)
{
	char	*leftovers;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || !line[i + 1])
		return (NULL);
	leftovers = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (!leftovers)
		return (NULL);
	return (leftovers);
}

static char	*linetrim(char *line)
{
	char	*new;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || !line[i + 1])
		return (line);
	new = ft_substr(line, 0, i);
	nulfree(&line);
	if (!new)
		return (NULL);
	return (new);
}

static char	*linefill(char *leftovers, int fd)
{
	char	*buff;
	ssize_t	bytes;

	buff = (char *)malloc((BUFFER_SIZE + 2) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = read(fd, buff, BUFFER_SIZE);
	while (bytes > 0)
	{
		buff[bytes] = '\0';
		leftovers = ft_strjoin(leftovers, buff);
		if (!leftovers)
		{
			nulfree(&buff);
			return (NULL);
		}
		if (ft_strchr(buff, '\n'))
			break ;
		bytes = read(fd, buff, BUFFER_SIZE);
	}
	nulfree(&buff);
	if (bytes < 0)
		return (NULL);
	return (leftovers);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	else if (len > slen - start)
		len = slen - start;
	result = malloc((len + 1));
	if (!result)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
