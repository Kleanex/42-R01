/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:20:54 by tguerin           #+#    #+#             */
/*   Updated: 2022/07/24 18:59:38 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_last_number(int tab[4][4], int nb_res);

void	ft_extrem_lines(int view_grid[6][6], int case_grid[4][4], int x)
{
	if (view_grid[x][0] == 1)
		case_grid[x - 1][0] = 4;
	if (view_grid[x][0] == 4)
	{
		case_grid[x - 1][0] = 1;
		case_grid[x - 1][1] = 2;
		case_grid[x - 1][2] = 3;
		case_grid[x - 1][3] = 4;
	}
	if (view_grid[x][5] == 1)
		case_grid[x - 1][3] = 4;
	if (view_grid[x][5] == 4)
	{
		case_grid[x - 1][0] = 4;
		case_grid[x - 1][1] = 3;
		case_grid[x - 1][2] = 2;
		case_grid[x - 1][3] = 1;
	}
}

void	ft_mid_lines(int view_grid[6][6], int case_grid[4][4], int y)
{
	if (view_grid[0][y] == 1)
		case_grid[0][y - 1] = 4;
	if (view_grid[0][y] == 4)
	{
		case_grid[0][y - 1] = 1;
		case_grid[1][y - 1] = 2;
		case_grid[2][y - 1] = 3;
		case_grid[3][y - 1] = 4;
	}
	if (view_grid[5][y] == 1)
		case_grid[3][y - 1] = 4;
	if (view_grid[5][y] == 4)
	{
		case_grid[0][y - 1] = 4;
		case_grid[1][y - 1] = 3;
		case_grid[2][y - 1] = 2;
		case_grid[3][y - 1] = 1;
	}
}

void	skyscrapers(int view_grid[6][6], int case_grid[4][4])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 5)
	{
		while (x < 5)
		{
			ft_extrem_lines(view_grid, case_grid, x);
			ft_mid_lines(view_grid, case_grid, y);
			x++;
		}
		y++;
		x = 0;
	}
	ft_find_last_number(case_grid, 4);
	ft_find_last_number(case_grid, 3);
	ft_find_last_number(case_grid, 2);
	ft_find_last_number(case_grid, 1);
}

void	solve(int case_grid[4][4], int view_grid[6][6])
{
	skyscrapers(view_grid, case_grid);
}
