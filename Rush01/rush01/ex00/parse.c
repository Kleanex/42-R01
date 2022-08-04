/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:05:24 by tguerin           #+#    #+#             */
/*   Updated: 2022/07/24 19:02:54 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(char *input)
{
	int	i;

	i = 0;
	while (input[i] && i < 31)
	{
		if (input[i] < '1' || input[i] > '4')
			return (0);
		if (!(input[i + 1] == ' ' || input[i + 1] == '\0'))
			return (0);
		i += 2;
	}
	if (i < 31 || input[i - 1])
		return (0);
	return (1);
}

int	parse(int grid[6][6], char *input)
{
	int	i;

	if (!is_valid(input))
		return (0);
	i = 0;
	while (i < 16)
	{
		if (i / 4 == 0)
			grid[i % 4 + 1][0] = input[i * 2] - '0';
		else if (i / 4 == 1)
			grid[i % 4 + 1][5] = input[i * 2] - '0';
		else if (i / 4 == 2)
			grid[0][i % 4 + 1] = input[i * 2] - '0';
		else if (i / 4 == 3)
			grid[5][i % 4 + 1] = input[i * 2] - '0';
		i += 1;
	}
	return (1);
}
