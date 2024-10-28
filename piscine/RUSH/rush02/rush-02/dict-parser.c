#include "rush-02.h"

t_dict	*parse_dict(const char *filename)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	t_dict	*dict;

	dict = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE - 1)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!process_buffer(buffer, &dict))
		{
			close(fd);
			free_dict(dict);
			return (NULL);
		}
	}
	close(fd);
	return (dict);
}

int	process_buffer(char *buffer, t_dict **dict)
{
	char	*line;
	char	*saveptr;

	line = strtok_r(buffer, "\n", &saveptr);
	while (line)
	{
		if (!process_line(line, dict))
			return (0);
		line = strtok_r(NULL, "\n", &saveptr);
	}
	return (1);
}

int	process_line(char *line, t_dict **dict)
{
	unsigned long long	key;

	char *key_str, *value;
	key_str = strtok(line, ":");
	value = strtok(NULL, ":");
	if (!key_str || !value)
		return (1); // Skip empty lines
	key = strtoull(key_str, NULL, 10);
	value = trim(value);
	if (!add_to_dict(dict, key, value))
		return (0);
	return (1);
}

int	add_to_dict(t_dict **dict, unsigned long long key, char *value)
{
	t_dict	*new_entry;

	new_entry = malloc(sizeof(t_dict));
	if (!new_entry)
		return (0);
	new_entry->key = key;
	new_entry->value = strdup(value);
	new_entry->next = *dict;
	*dict = new_entry;
	return (1);
}

void	free_dict(t_dict *dict)
{
	t_dict *temp;

	while (dict)
	{
		temp = dict;
		dict = dict->next;
		free(temp->value);
		free(temp);
	}
}