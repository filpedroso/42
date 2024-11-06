/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:11:32 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/06 21:19:38 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char ch);
static void		populator(char **final, const char *str, char ch);
static char		*strdup2(const char *begin, const char *end);

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**final;

	if (!s)
		return (NULL);
	if (c == '\0')
	{
		final = (char **)ft_calloc(1, (size_t)((2) * sizeof(char *)));
		if (!final)
			return (NULL);
		final[0] = ft_strdup(s);
		if (!final[0])
			return (NULL);
		final[1] = NULL;
		return (final);
	}
	count = count_words(s, c);
	final = (char **)ft_calloc(1, (size_t)((count + 1) * sizeof(char *)));
	if (!final)
		return (NULL);
	populator(final, s, c);
	return (final);
}

static void	populator(char **final, const char *str, char ch)
{
	const char	*next;
	size_t		i;

	i = 0;
	while (*str == ch)
		str++;
	while (*str)
	{
		next = ft_strchr(str, (int)ch);
		if (next)
		{
			final[i++] = strdup2(str, next);
			str = next + 1;
			while (*str == ch)
				str++;
		}
		else
		{
			if (*str)
				final[i] = ft_strdup(str);
			if (!final[i])
				return ;
			break ;
		}
	}
}

static char	*strdup2(const char *begin, const char *end)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = end - begin;
	str = (char *)ft_calloc(1, len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = begin[i];
		i++;
	}
	return (str);
}

static size_t	count_words(const char *str, char ch)
{
	const char	*next;
	size_t		count;

	count = 0;
	while (*str == ch)
		str++;
	while (*str)
	{
		next = ft_strchr(str, ch);
		if (next)
		{
			count++;
			str = next + 1;
			while (*str == ch)
				str++;
		}
		else
		{
			if (*str)
				count++;
			break ;
		}
	}
	return (count);
}

/* int	main(void)
{
	const char	*stri = "amanheceu  peguei a   viola  ";
	char		**strings;

	strings = ft_split(stri, ' ');
	for (char **s = strings; *s; s++)
	{
		printf("%s\n", *s);
		free(*s);
	}
	free(strings);
	printf("the end");
} */
