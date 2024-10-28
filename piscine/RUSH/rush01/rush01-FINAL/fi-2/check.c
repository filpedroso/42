/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:42:22 by asafrono          #+#    #+#             */
/*   Updated: 2024/09/29 15:48:55 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

static void	update_values(int *visible, int *max_height, int new_height)
{
	(*visible)++;
	*max_height = new_height;
}

static int	check_line(int grid[SIZE][SIZE], int i, int j, int view)
{
	int	visible;
	int	max_height;
	int	k;

	visible = 0;
	max_height = 0;
	if (i % 2 == 0)
		k = 0;
	else
		k = SIZE - 1;
	while (k >= 0 && k < SIZE)
	{
		if (i < 2 && grid[k][j] > max_height)
			update_values(&visible, &max_height, grid[k][j]);
		else if (i >= 2 && grid[j][k] > max_height)
			update_values(&visible, &max_height, grid[j][k]);
		if (i % 2 == 0)
			k++;
		else
			k--;
	}
	return (visible == view);
}

int	check_view(int grid[SIZE][SIZE], int views[SIZE][SIZE])
{
	int	i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			if (!check_line(grid, i, j, views[i][j]))
				return (0);
		}
	}
	return (1);
}
