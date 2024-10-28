/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:07:45 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/02 16:56:23 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int				result;
	unsigned char	char1;
	unsigned char	char2;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	char1 = (unsigned char) *s1;
	char2 = (unsigned char) *s2;
	result = char1 - char2;
	return (result);
}
/*int	main(void)
{
	char	*s1 = "kamehamehd";
	char	*s2 = "kamehameha";

	int res = ft_strcmp(s1, s2);

	printf("result = %i\n", res);
}*/
