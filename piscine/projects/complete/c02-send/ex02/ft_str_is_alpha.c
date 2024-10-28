/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:39:57 by fpedroso          #+#    #+#             */
/*   Updated: 2024/09/29 13:45:21 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			return (0);
		str++;
	}
	return (1);
}
/*int	main(void)
{
	char camarao[] = "camarao";
	int r1 = ft_str_is_alpha(camarao);
	int r01 = ft_str_is_alpha("cama/^");
	int r02 = ft_str_is_alpha("");
	int r03 = ft_str_is_alpha("/^&");

	printf("camarao = %i, cama/^ = %i, '' = %i, /^& = %i", r1, r01, r02, r03);
}*/
