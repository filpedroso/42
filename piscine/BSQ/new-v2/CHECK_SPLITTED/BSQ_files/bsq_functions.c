/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvalim-d <cvalim-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:03:10 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/10/09 22:12:31 by cvalim-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

char	*ft_tiktok(char *str, char delimiter)
{
	static char	*current_position;
	char		*start;

	if (str)
	{
		current_position = str; // Atualiza a posição atual
	}
	if (!current_position || *current_position == '\0')
		// Verifica se não há mais string
	{
		return (NULL);
	}
	start = current_position;
		// Marca o início da nova substring
	while (*current_position && *current_position != delimiter)
		// Avança até o delimitador
	{
		current_position++;
	}
	if (*current_position) // Se encontrou o delimitador
	{
		*current_position = '\0'; // Substitui por terminador
		current_position++;       // Move para o próximo caractere
	}
	return (start); // Retorna a substring
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*final;

	final = (char *)malloc((n + 1) * sizeof(char));
	if (final == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] && i < n)
	{
		final[i] = s[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*final;
	int		len;

	len = ft_strlen(s);
	final = (char *)malloc((len + 1) * sizeof(char));
	if (final == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		final[i] = s[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}

void	print_map_error(void)
{
	write(2, "map error\n", 10);
}
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
