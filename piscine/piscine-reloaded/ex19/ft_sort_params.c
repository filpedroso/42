/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:37:52 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/25 15:28:33 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putargs(int count, char **str);
int		ft_strcmp(char *str1, char *str2);
void	sort_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	if (argc < 1)
	{
		write (1, "\n", 1);
		return (0);
	}
	sort_args(argc, argv);
	ft_putargs(argc, argv);
	return (0);
}

void	sort_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	*swap;

	swap = NULL;
	i = 1;
	while (i < argc)
	{
		j = i;
		while (j < (argc - 1))
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				swap = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}

void	ft_putargs(int count, char **str)
{
	if (count > 1)
	{
		while (*++str)
		{
			while (**str)
			{
				write (1, *str, 1);
				(*str)++;
			}
			write (1, "\n", 1);
		}
		return ;
	}
	return ;
}

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
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
