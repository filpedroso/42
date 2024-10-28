/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:38:33 by fpedroso          #+#    #+#             */
/*   Updated: 2024/09/23 17:32:05 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;
	int	temp2;

	temp = *a / *b;
	temp2 = *a % *b;
	*a = temp;
	*b = temp2;
}

/*int	main(void)
{
	int a = 42;
	int b = 4;
	
	printf("%i %i", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("%i %i", a, b);
}*/
