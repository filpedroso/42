/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:43:45 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/05 20:19:27 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned int	ft_strlen(char *base);
void			deliciously_recursive(unsigned int nbr, char *base,
					unsigned int base_len);
int				is_valid_base(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	positive_nbr;

	if (!is_valid_base(base))
		return ;
	if (nbr < 0)
	{
		positive_nbr = -((unsigned int)nbr);
		write(1, "-", 1);
	}
	else
		positive_nbr = (unsigned int)nbr;
	base_len = ft_strlen(base);
	deliciously_recursive(positive_nbr, base, base_len);
}

void	deliciously_recursive(unsigned int nbr, char *base,
		unsigned int base_len)
{
	if (nbr >= base_len)
		deliciously_recursive(nbr / base_len, base, base_len);
	write(1, &base[nbr % base_len], 1);
}

unsigned int	ft_strlen(char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

int	is_valid_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	main(void)
{
	int a = 0;
	int n = 1;
	int o = -2147483648;
	int p =11;
	int q = 247;
	int r = 12465777;


	ft_putnbr_base(o, "0123456789");
}
