/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:07:34 by fpedroso          #+#    #+#             */
/*   Updated: 2024/09/29 12:58:31 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src[i] == '\0')
		{
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
		}
		else
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}

/*int   main(void)
{
        char    *src = "new world";
        char    dest[13];
	int	w = 20;
        ft_strncpy(dest, src, w);
	for (int t = 0; t <= w; t++)
	{
		if (dest[t] == '\0') dest[t] = '0';
		write (1, &dest[t], 1);
	}
        printf("\n%s\n", dest);
}*/
