/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:45:16 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/06 21:19:53 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

int	print_word(t_dict *dict, const char *key)
{
	while (dict)
	{
		if (ft_strcmp(dict->key, key) == 0)
		{
			write(1, dict->value, ft_strlen(dict->value));
			return (1);
		}
		dict = dict->next;
	}
	return (0);
}

void	ft_strncpy(char *dst, const char *src, int n)
{
	int	i;

	i = 0;
	while ((i < n) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
}

void	ft_strcat(char *dst, const char *src)
{
	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	create_and_print_scale(t_dict *dict, char *scale, int scale_len)
{
	int	i;

	write(1, " ", 1);
	scale[0] = '1';
	scale[1] = '\0';
	i = -1;
	while (++i < scale_len)
		ft_strcat(scale, "0");
	if (!print_word(dict, scale))
		return (0);
	return (1);
}
