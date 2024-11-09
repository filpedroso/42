/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:11:32 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/08 16:42:12 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char ch);
static void		populator(char **final, const char *str, char ch);
static char		*strdup2(const char *begin, const char *end);
static void		ft_freestrs(char **strings);

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**final;

	if (!s)
		return (NULL);
	if (c == '\0')
	{
		final = (char **)malloc(2 * sizeof(char *));
		if (!final)
			return (NULL);
		final[0] = ft_strdup(s);
		if (!final[0])
			return (NULL);
		final[1] = NULL;
		return (final);
	}
	count = count_words(s, c);
	final = (char **)malloc((count + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	while (*s == c)
		s++;
	populator(final, s, c);
	return (final);
}

static void	populator(char **final, const char *str, char ch)
{
	const char	*next;
	size_t		i;

	i = 0;
	while (*str)
	{
		next = ft_strchr(str, (int)ch);
		if (next)
		{
			final[i] = strdup2(str, next);
			if (!final[i])
			{
				ft_freestrs(final);
				return ;
			}
			str = next + 1;
			while (*str == ch)
				str++;
			i++;
		}
		else
		{
			final[i] = ft_strdup(str);
			if (!final[i])
			{
				ft_freestrs(final);
				return ;
			}
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
	str = (char *)malloc(len + 1);
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

static void	ft_freestrs(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
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
