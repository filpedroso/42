/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:42:25 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/27 18:51:41 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	for (int i = 0; i < 95; i++)
	{
		int	c = i + 32;
		ft_isalnum(c) ? printf("%c is alphanum: YES | ", c) : printf("%c Is alphanum: NO |", c);
		ft_isalpha(c) ? printf("%c is alpha: YES | ", c) : printf("%c is alpha: NO | ", c);
		ft_isdigit(c) ? printf("%c is digit: YES\n", c) : printf("%c is digit: NO\n", c);
	}
}
