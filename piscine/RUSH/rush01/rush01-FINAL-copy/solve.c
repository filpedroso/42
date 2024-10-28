/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:44:17 by asafrono          #+#    #+#             */
/*   Updated: 2024/09/29 16:37:25 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int	check_view(int grid[SIZE][SIZE], int views[SIZE][SIZE]);
int	is_valid(int grid[SIZE][SIZE], int row, int col, int num);

int	solve(int grid[SIZE][SIZE], int row, int col, int views[SIZE][SIZE])
{
	int	num;

	if (row == SIZE)
		return (check_view(grid, views));
	if (col == SIZE)
		return (solve(grid, row + 1, 0, views));
	num = 1;
	while (num <= SIZE)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, row, col + 1, views))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
