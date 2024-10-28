/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_say.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:04:54 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/23 13:33:50 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	if (argc != 2)
		return (1);
	i = 0;
	while (argv[1][i] != '\0')
	{
		count = 1;
		j = i + 1;
		while (argv[1][i] == argv[1][j])
		{
			count++;
			j++;
			i++;
		}
		if (argv[1][i + 1] == '\0')
		{
			printf("%i%c\n", count, argv[1][i]);
			return (0);
		}
		printf("%i%c ", count, argv[1][i]);
		i++;
	}
}
