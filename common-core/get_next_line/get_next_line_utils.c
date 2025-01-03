/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:13:22 by fpedroso          #+#    #+#             */
/*   Updated: 2024/12/04 15:14:08 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	if (!s)
		return (0);
	ptr = s;
	while (*ptr)
	{
		ptr++;
	}
	return ((size_t)(ptr - s));
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
	{
		s2 = (char *)malloc(1 * sizeof(char));
		if (!s2)
			return (NULL);
		s2[0] = '\0';
		return (s2);
	}
	s2 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	ch;

	ptr = (char *)s;
	ch = (char)c;
	while (*ptr)
	{
		if (*ptr == ch)
		{
			return (ptr);
		}
		ptr++;
	}
	if (ch == '\0')
	{
		return (ptr);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	total_len;
	size_t	i;
	size_t	j;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc((total_len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		i++;
		j++;
	}
	s3[total_len] = '\0';
	return (s3);
}

void	nulfree(char **str)
{
	if (*str == NULL)
		return ;
	free(*str);
	*str = NULL;
	return ;
}
