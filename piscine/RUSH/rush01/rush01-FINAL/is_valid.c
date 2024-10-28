/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:43:04 by asafrono          #+#    #+#             */
/*   Updated: 2024/09/29 16:31:14 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int	is_valid(int grid[SIZE][SIZE], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_input(char *input)
{
	int	count;

	count = 0;
	while (*input)
	{
		if (count % 2 == 0)
		{
			if (*input < '1' || *input > (SIZE + '0'))
				return (0);
		}
		else if (*input != ' ')
			return (0);
		input++;
		count++;
	}
	return (count == (SIZE * SIZE * 2 - 1));
}
