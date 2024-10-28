/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:26:07 by fpedroso          #+#    #+#             */
/*   Updated: 2024/09/25 10:46:58 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
	{
		*div = 0;
		*mod = 0;
		return ;
	}
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int a = 10;
	int b = 0;
	int div = 42;
	int mod = 88;

	printf("%i %i %i %i", a, b, div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("%i %i %i %i", a, b, div, mod);
}*/
