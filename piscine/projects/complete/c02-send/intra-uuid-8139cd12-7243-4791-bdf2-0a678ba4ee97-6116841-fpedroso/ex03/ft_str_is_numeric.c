/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:37:03 by fpedroso          #+#    #+#             */
/*   Updated: 2024/09/26 17:55:35 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	if (!*str)
		return (1);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
/*int	main(void)
{
        int n1 = ft_str_is_numeric("123");
        int n01 = ft_str_is_numeric("numbers");
        int n2 = ft_str_is_numeric("");
        int n3 = ft_str_is_numeric("1234565775957546a25891");

        printf("1 = %i, 0 = %i, 1 = %i, 0 = %i", n1, n01, n2, n3);
}*/
