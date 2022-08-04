/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosteine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:23:25 by dosteine          #+#    #+#             */
/*   Updated: 2022/07/24 12:55:05 by dosteine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*a = tmp;
}

int	heapfy (int array [], int n, int i)
{
	int left, right, largeur;

	largeur = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < n && array [left] > array [largeur])
		largeur = left;
	if (right < n && array [right] > array [largeur])
		largeur = right;
	if (largeur != i)
	{
		ft_swap (&array[i], &array[largeur]);
		heapfy(array, n, largeur);
	}
	return(i);
}

void heapfoy (int array[], int n)
{
	int i;

	for (i = (n / 2)-1; i >= 0; i--)
	{
		heapfy (array, n, i);
	}
	
	for (i = n - 1; i >= 0; i--)
	{
		ft_swap(&array[0], &array[i]);
		heapfy(array, i, 0);
	}
}

int main()
{
	
	int array[]={4,3,2,1,1,2,2,2,4,3,2,1,1,2,2,2};
	int n = sizeof (array) / sizeof (array[0]);
	int i = 4;
	
	printf("Array:\n");
	
	heapfy(array, n, i);
	for (int i = 0; i < 0 ; i++)
	{
		printf("%d\n ", array[i]);
	
	}

	heapfoy(array, n);

	printf("\nAfter heapfoy:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);	
	}
	return (0);
}
