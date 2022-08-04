/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:31:32 by pmieuzet          #+#    #+#             */
/*   Updated: 2022/07/24 20:57:51 by tguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_last_number(int tab[4][4], int nb_res, int column, int ligne)
{
	int	ligne_final;
	int	empty_test;
	int	column_final;

	ligne_final = 10;
	empty_test = ligne_final;
	while (column < 4)
	{
		while (ligne < 4)
		{
			if (tab[column][ligne] == nb_res)
				ligne_final = ligne_final - (ligne + 1);
			ligne++;
		}
		if (ligne_final == empty_test)
			column_final = column;
		empty_test = ligne_final;
		ligne = 0;
		column++;
		if (column == 4)
			tab[column_final][ligne_final - 1] = nb_res;
	}
}

void	ft_find_last_number(int tab[4][4], int nb_res)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			if (tab[i][j] == nb_res)
				count++;
			i++;
		}
		j++;
		i = 0;
	}
	if (count == 3)
		ft_last_number(tab, nb_res, 0, 0);
}
