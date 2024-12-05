/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:34:03 by fpedroso          #+#    #+#             */
/*   Updated: 2024/12/05 19:04:38 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(leftovers);
		leftovers = NULL;
		return (NULL);
	}
	line = linefill(leftovers, fd);
	if (!line)
		return (NULL);
	leftovers = recycler(line); //return a ft_strdup("") in case there's no leftovers
	if (!leftovers)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

static char	*recycler(char *line)
{
	int	i;

	i = 0;
	while
}

static char	*linefill(char *leftovers, int fd)
{
	char	*buff;
	char	*line;
	ssize_t	n_bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!leftovers)
		leftovers = ft_strdup("");
	if (!buff)
	{
		free(leftovers);
		leftovers = NULL;
		return (NULL);
	}
	n_bytes = read(fd, buff, BUFFER_SIZE);
	if (n_bytes == 0 || n_bytes == -1)
	{
		free(leftovers);
		leftovers = NULL;
		free(buff);
		return (NULL);
	}
	buff[n_bytes] = 0;
	line = help_linefill(leftovers, buff, fd, n_bytes);
	free(buff);
	return (line);
}

static char	*help_linefill(char *leftovers, char *buff, int fd, ssize n_bytes)
{
	char *line;

	while (n_bytes > 0)
	{
		line = ft_strjoin(leftovers, buff);
		free(leftovers);
		leftovers = line;
		if (!line)
			return (NULL);
		if (ft_strchr(buff, '\n'))
			break ;
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == 0)
			break ;
		if (n_bytes == -1)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

