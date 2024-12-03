/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:13:18 by fpedroso          #+#    #+#             */
/*   Updated: 2024/12/03 14:52:22 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*linetrim_nl(char *leftovers);
static char	*ft_strdup_nl(char *leftovers);
static char	*linefill(char *leftovers, char *buff, int fd);

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*line;
	char		*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff || fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(leftovers);
		free(buff);
		return (NULL);
	}
	leftovers = linefill(leftovers, buff, fd);
	if (!leftovers)
		return (NULL);
	line = ft_strdup_nl(leftovers);
	leftovers = linetrim_nl(leftovers);
	free(buff);
	return (line);
}

static char	*linetrim_nl(char *leftovers)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (leftovers[i] != '\n')
		i++;
	new = (char *)malloc(((ft_strlen(leftovers) - i) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (leftovers[i])
	{
		new[j] = leftovers[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(leftovers);
	return (new);
}

static char	*ft_strdup_nl(const char *leftovers)
{
	char	*line;
	int		i;

	i = 0;
	if (!leftovers[i])
		return (NULL);
	while (leftovers[i] && leftovers[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (leftovers[i] && leftovers[i] != '\n')
	{
		line[i] = leftovers[i];
		i++;
	}
	if (leftovers[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*linefill(char *leftovers, char *buff, int fd)
{
	ssize_t	bytes;

	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(leftovers);
			free(buff);
			return (NULL);
		}
		if (!bytes)
			break ;
		buff[bytes] = '\0';
		leftovers = ft_strjoin(leftovers, buff);
		if (!leftovers)
		{
			free(buff);
			return (NULL);
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (leftovers);
}
