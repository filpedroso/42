/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:06:32 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/06 21:21:27 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

t_dict	*parse_dict(const char *filename)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	t_dict	*dict;

	dict = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!process_buffer(buffer, &dict))
		{
			close(fd);
			free_dict(dict);
			return (NULL);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	}
	close(fd);
	return (dict);
}

int	process_buffer(char *buffer, t_dict **dict)
{
	char	*line_start;
	char	*line_end;

	line_start = buffer;
	line_end = ft_strchr(line_start, '\n');
	while (line_end)
	{
		*line_end = '\0';
		if (!process_line(line_start, dict))
			return (0);
		line_start = line_end + 1;
		line_end = ft_strchr(line_start, '\n');
	}
	if (*line_start)
		if (!process_line(line_start, dict))
			return (0);
	return (1);
}

int	process_line(char *line, t_dict **dict)
{
	char	*colon;
	char	*key;
	char	*value;

	colon = ft_strchr(line, ':');
	if (!colon)
		return (1);
	*colon = '\0';
	key = ft_trim(line);
	value = ft_trim(colon + 1);
	if (!add_to_dict(dict, key, value))
		return (0);
	return (1);
}

int	add_to_dict(t_dict **dict, char *key, char *value)
{
	t_dict	*new_entry;

	new_entry = malloc(sizeof(t_dict));
	if (!new_entry)
	{
		return (0);
	}
	new_entry->key = ft_strdup(key);
	new_entry->value = ft_strdup(value);
	new_entry->next = *dict;
	*dict = new_entry;
	return (1);
}

int	ft_atoi(const char *str)
{
	int	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}
