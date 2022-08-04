/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosteine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:23:28 by dosteine          #+#    #+#             */
/*   Updated: 2022/07/24 20:37:58 by dosteine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*a = tmp;
}

int heap (int n, int array[])
{
	int i;
	int compteur[16];

	i=0;		
	while (i >= 0 && array[n])
	{
		if ((i%2)!= 0)
		{
			ft_swap(&array[0], &array[i]);
			compteur[i] += 1;
		}
		else
		{
			ft_swap(&array[i], &array[i+1]);
			compteur[i] += i;
		}
	if (n > 0)
		heap (n - 1, array);
	else	
		return (array[n]);
}
/*int	heap (int n, int array[])
{
	int	compteur[16];
	int i;
	
	i = 0;
	while (i < n)
	{
		if (compteur[i] < n)
		{
			if ((i%2)!= 0)
				ft_swap(&array[0], &array[i]);
			else
			{
				ft_swap(&array[i], &array[i+1]);
				compteur[i] = i++;
			}
			compteur[i] = i;
		i++;
		heap(n, array);
		}
	}
	return (array[n]);
}	
*/
#include <stdio.h>

int main()
{
	int grid[]={4,3,2,1,1,2,2,2,1,2,3,4,1,2,2,2};
	int n = sizeof(grid) / sizeof(grid[16]);
//  int i = 0;

	printf("%d", heap (n, grid));
	return (0);
}

