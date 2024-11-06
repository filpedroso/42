/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:11:32 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/06 15:34:13 by fpedroso         ###   ########.fr       */
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
	count = count_words(s, c);
	final = (char **)ft_calloc(1, (size_t)((count + 1) * sizeof(char **)));
	final[count] = NULL;
	populator(final, s, c);
	return (final);
}

static void	populator(char **final, const char *str, char ch)
{
	const char	*next;

	while (*str == ch)
		str++;
	while (*(final))
	{
		next = ft_strchr(str, (int)ch);
		if (next)
		{
			*final = strdup2(str, next);
			str = next + 1;
			while (*str == ch)
				str++;
		}
		else
		{
			if (*str)
				*final = ft_strdup(str);
			break ;
		}
		final++;
	}
}

static char	*strdup2(const char *begin, const char *end)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = end - begin;
	str = (char *)ft_calloc(1, len + 1);
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

int	main(void)
{
	const char	*stri = "amanheceu  peguei a    viola botei na   caixola e fui viajar ";
	char		**strings;

	strings = ft_split(stri, ' ');
	for (char **s = strings; *s; s++)
	{
		printf("%s\n", *s);
		free(*s);
	}
	free(strings);
	printf("the end");
}
