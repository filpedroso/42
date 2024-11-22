/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:24:19 by fpedroso          #+#    #+#             */
/*   Updated: 2024/11/21 20:58:43 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char **format, t_flags *flags)
{
	while (**format && (ft_isdigit(**format) || is_flag(**format)))
	{
		if (**format == '-')
		{
			flags->left_justify = 1;
			flags->zero_padding = 0;
		}
		else if (**format == '0' && flags->width == 0
			&& flags->left_justify == 0)
			flags->zero_padding = 1;
		else if (**format == '.')
		{
			flags->precision = ft_atoi(*format + 1);
			*format += num_len(flags->precision);
			continue ;
		}
		else if (ft_isdigit(**format) && flags->precision == -1)
		{
			flags->width = ft_atoi(*format);
			*format += num_len(flags->width);
			continue ;
		}
		(*format)++;
	}
}

int	content_len(const char **str, va_list *args_p)
{
	int	count;

	count = 0;
	if (**str == 'c')
		count = 1;
	else if (**str == 's')
		count = ft_strlen(va_arg(*args_p, char *));
	else if (**str == 'i' || **str == 'd')
		count = num_len(va_arg(*args_p, int));
	else if (**str == 'u')
		count = num_len((long long)va_arg(*args_p, unsigned int));
	else if (**str == 'p')
		count = 2 + num_len((long long)(uintptr_t)va_arg(*args_p, void *));
	else if (**str == 'x' || **str == 'X')
		count = num_len((long long)va_arg(*args_p, unsigned int));
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*
no truncation
zero-pad (0) ->		left-padding, but ignored if '-' was used,
			or '.' was used on an int.
					prints zeros only if width is bigger than strlen of printed.
precision (.) ->	minimum digits to be printed for iduxX,
					padding with zeros on the left
					for strings means the maximum chars to be printed,
						cropping the string
left-justify (-) ->	left justifies using width, pads with spaces on the right.
width (0-9) ->		specifies width for (-) or (0).

 */