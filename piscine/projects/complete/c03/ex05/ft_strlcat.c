/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:40:17 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/02 16:26:03 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < dest_len)
	{
		return (size + src_len);
	}
	i = dest_len;
	j = 0;
	while (i < (size - 1) && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}

/*int main()
{
	char dest[20] = "Hello, ";
	char src[] = "world!";
	unsigned int size = sizeof(dest);
	unsigned int result;

	printf("Before ft_strlcat:\n");
	printf("dest: \"%s\"\n", dest);
	printf("src: \"%s\"\n", src);
	printf("size: %u\n\n", size);

	result = ft_strlcat(dest, src, size);

	printf("After ft_strlcat:\n");
	printf("dest: \"%s\"\n", dest);
	printf("Return value: %u\n", result);

	return (0);
}*/
