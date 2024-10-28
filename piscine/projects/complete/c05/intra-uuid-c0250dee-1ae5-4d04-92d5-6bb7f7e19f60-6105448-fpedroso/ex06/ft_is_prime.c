/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:34:43 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/06 12:52:15 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb);

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	sqrt = ft_sqrt(nb);
	i = 2;
	while (i <= sqrt)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_sqrt(int nb)
{
	int	i;
	int	lower;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	lower = i - 1;
	if (nb - (lower * lower) <= (i * i) - nb)
	{
		return (lower);
	}
	else
	{
		return (i);
	}
}

/*int main()
{
	int	number;
	int	sqrt_result;

	number = 17;
	if (ft_is_prime(number))
	{
		printf("%d is a prime number.\n", number);
	}
	else
	{
		printf("%d is not a prime number.\n", number);
	}
	number = 18;
	if (ft_is_prime(number))
	{
		printf("%d is a prime number.\n", number);
	}
	else
	{
		printf("%d is not a prime number.\n", number);
	}
	number = 20;
	sqrt_result = ft_sqrt(number);
	printf("The square root of %d rounded to the nearest integer is %d\n",
		number, sqrt_result);
	return (0);
}*/
