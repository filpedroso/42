/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:11:55 by asafrono          #+#    #+#             */
/*   Updated: 2024/09/29 16:36:45 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define SIZE 4  // Define the size of the grid (4x4)

void	ft_putstr(char *str);
void	print_solution(int grid[SIZE][SIZE]);
int		check_view(int grid[SIZE][SIZE], int views[SIZE][SIZE]);
int		is_valid(int grid[SIZE][SIZE], int row, int col, int num);
int		solve(int grid[SIZE][SIZE], int row, int col, int views[SIZE][SIZE]);
int		is_valid_input(char *input);

void	init_grid(int grid[SIZE][SIZE])
{
	int	x;
	int	y;

	x = 0;
	while (x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			grid[x][y] = 0;
			y++;
		}
		x++;
	}
}

void	parse_input(char *input, int views[SIZE][SIZE])
{
	int	i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
			views[i][j] = input[i * SIZE * 2 + j * 2] - '0';
	}
}

int	main(int argc, char **argv)
{
	int		views[SIZE][SIZE];
	int		grid[SIZE][SIZE];
	char	*input;

	if (argc != 2 || !is_valid_input(argv[1]))
	{
		ft_putstr("Error\n");
		return (1);
	}
	input = argv[1];
	init_grid(grid);
	parse_input(input, views);
	if (solve(grid, 0, 0, views))
		print_solution(grid);
	else
		ft_putstr("Error\n");
	return (0);
}
