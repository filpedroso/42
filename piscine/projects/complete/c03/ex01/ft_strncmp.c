/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:52:05 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/02 16:13:58 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	char1;
	unsigned char	char2;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	if (i == n)
		return (0);
	char1 = (unsigned char)s1[i];
	char2 = (unsigned char)s2[i];
	return (char1 - char2);
}

/*int main() {
    printf("%d\n", ft_strncmp("hello", "hello", 5));
    printf("%d\n", ft_strncmp("hello", "hell", 5));
    printf("%d\n", ft_strncmp("hell", "hello", 5));
    printf("%d\n", ft_strncmp("abc", "abcde", 3)); 
    printf("%d\n", ft_strncmp("abc", "abC", 3));
    return 0;
}*/

/*int   main(void)
{
	char    *s1 = "kamehamehd";
	char    *s2 = "kamehameha";

	int res = ft_strcmp(s1, s2);

	printf("i = %i\n", res);
}*/
