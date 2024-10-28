/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:54:49 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/02 16:20:58 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (&str[i]);
			}
		}
		i++;
	}
	return (NULL);
}
/*int main()
{
    char str[] = "Hello, world, my name is hirax and I came here to rock";
    char to_find[] = "rock";

    char *result = ft_strstr(str, to_find);

    if (result != NULL)
    {
        printf("Found substring: %s\n", result);
    }
    else
    {
        printf("Substring not found\n");
    }

    return 0;
}*/
