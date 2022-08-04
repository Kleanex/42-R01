/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:20:29 by tguerin           #+#    #+#             */
/*   Updated: 2022/07/24 19:09:58 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	parse(int grid[6][6], char *input);
void	print_result(int grid[4][4]);
void	solve(int case_grid[4][4], int view_grid[6][6]);
void	init_grid(int size, int grid[size][size])
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			grid[x][y] = 0;
			x++;
		}
		y++;
	}
}

void	play(char *input)
{
	int	view_grid[6][6];
	int	case_grid[4][4];

	init_grid(6, view_grid);
	init_grid(4, case_grid);
	if (!parse(view_grid, input))
	{
		write(1, "Error\n", 8);
		return ;
	}
	solve(case_grid, view_grid);
	print_result(case_grid);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Error\n", 8);
		return (0);
	}
	play(argv[1]);
	return (0);
}
