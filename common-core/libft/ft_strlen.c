/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:29:01 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/28 14:07:11 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Uses pointer incrementing and arithmetic in the end for fastest possible algorithm.
However standard strlen is still very much faster  */

size_t	ft_strlen(const char *s)
{
	const char *ptr;

	if (s == NULL)
	{
		return (0);
	}

	ptr = s;
	while (*ptr)
	{
		ptr++;
	}
	return ((size_t)(ptr - s));
}
