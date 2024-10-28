/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:49:52 by fpedroso          #+#    #+#             */
/*   Updated: 2024/09/20 20:40:36 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	nn;
	char	pp;

	nn = 'N';
	pp = 'P';
	if (n < 0)
	{
		write(1, &nn, 1);
	}
	else
	{
		write(1, &pp, 1);
	}
	return ;
}

/*int	main(void)
{
	ft_is_negative(-1);
	return 0;
}*/
