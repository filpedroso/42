/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:02:27 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/10 21:06:11 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*concat(int size, char **strs, char *str, char *sep)
{
	int	i;
	int	j;
	int	new_str;

	i = 0;
	new_str = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[new_str++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				str[new_str++] = sep[j++];
		}
		i++;
	}
	str[new_str] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		total_length;
	int		i;

	i = 0;
	total_length = 0;
	while (i < size)
	{
		total_length = total_length + ft_strlen(strs[i]);
		if (i < size - 1)
			total_length = total_length + ft_strlen(sep);
		i++;
	}
	string = malloc(total_length + 1);
	if (string == NULL)
		return (NULL);
	concat(size, strs, string, sep);
	return (string);
}

/* #include <stdio.h>

int	main(void)
{
	char	*sep;
	char	*str[2];
	char	*result;

	sep = " ";
	str[0] = "1234";
	str[1] = "5678";
	result = ft_strjoin(2, str, sep);
	printf("strjoin is: %s\n", result);
	free(result);
	return (0);
} */