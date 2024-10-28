/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:45:46 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/06 21:16:19 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

int	convert_and_print(t_dict *dict, const char *number_str)
{
	while (*number_str == '0' && *(number_str + 1) != '\0')
		number_str++;
	if (*number_str == '\0')
		return (print_word(dict, "0"));
	if (!print_number(dict, number_str))
		return (0);
	return (1);
}

int	print_number(t_dict *dict, const char *num)
{
	int	len;

	len = ft_strlen(num);
	if (len <= 2)
		return (print_two_digits(dict, num));
	else if (len == 3)
		return (print_three_digits(dict, num));
	else
		return (print_large_number(dict, num, len));
}

int	print_two_digits(t_dict *dict, const char *num)
{
	int		value;
	char	buffer[3];

	value = ft_atoi(num);
	if (value <= 19)
	{
		return (print_word(dict, num));
	}
	else
	{
		buffer[0] = num[0];
		buffer[1] = '0';
		buffer[2] = '\0';
		if (!print_word(dict, buffer))
			return (0);
		if (num[1] != '0')
		{
			write(1, " ", 1);
			buffer[0] = num[1];
			buffer[1] = '\0';
			return (print_word(dict, buffer));
		}
	}
	return (1);
}

int	print_three_digits(t_dict *dict, const char *num)
{
	char	buffer[2];

	buffer[0] = num[0];
	buffer[1] = '\0';
	if (!print_two_digits(dict, buffer))
		return (0);
	write(1, " hundred", 8);
	if (num[1] != '0' || num[2] != '0')
	{
		write(1, " ", 1);
		convert_and_print(dict, num + 1);
	}
	return (1);
}

int	print_large_number(t_dict *dict, const char *num, int len)
{
	int		group_size;
	int		first_group_size;
	char	group[4];
	char	scale[40];
	int		scale_len;

	group_size = 3;
	first_group_size = len % group_size;
	if (first_group_size == 0)
		first_group_size = group_size;
	scale_len = len - first_group_size;
	ft_strncpy(group, num, first_group_size);
	group[first_group_size] = '\0';
	if (!convert_and_print(dict, group))
		return (0);
	if ((scale_len > 0) && !create_and_print_scale(dict, scale, scale_len))
		return (0);
	if (scale_len > 0 && ft_strcmp(num + first_group_size, "000") != 0)
	{
		write(1, " ", 1);
		return (convert_and_print(dict, num + first_group_size));
	}
	return (1);
}
