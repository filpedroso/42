/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:13:45 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/10 20:41:21 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*temp;

	dest = malloc(ft_strlen(src) + 1);
	if (!dest)
	{
		return (0);
	}
	temp = dest;
	while (*src)
	{
		*temp++ = *src++;
	}
	*temp = '\0';
	return (dest);
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

/* int main()
{
	char str[] = "jacare de parede";
	char *new = ft_strdup(str);
	for (int i = 0; i < ft_strlen(str); i++)
	{
		printf("%c", new[i]);
	}
} */
