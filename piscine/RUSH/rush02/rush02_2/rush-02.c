/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpedroso <fpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:16:15 by fpedroso          #+#    #+#             */
/*   Updated: 2024/10/06 21:21:02 by fpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush-02.h"

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number_str;

	dict_path = "numbers.dict";
	if (argc < 2 || argc > 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 3)
	{
		dict_path = argv[1];
		number_str = argv[2];
	}
	else
		number_str = argv[1];
	if (!is_valid_number(number_str))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	help_main(number_str, dict_path);
}

int	help_main(char *number_str, char *dict_path)
{
	t_dict	*dict;

	dict = parse_dict(dict_path);
	if (!dict)
	{
		write(2, "Dict Error\n", 11);
		return (1);
	}
	if (!convert_and_print(dict, number_str))
	{
		write(2, "Dict Error\n", 11);
		free_dict(dict);
		return (1);
	}
	free_dict(dict);
	write(1, "\n", 1);
	return (0);
}

void	free_dict(t_dict *dict)
{
	t_dict	*temp;

	while (dict)
	{
		temp = dict;
		dict = dict->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}
