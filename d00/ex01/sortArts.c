/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:07:45 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/23 14:14:56 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	swap(t_art **arts, int i, int j)
{
	t_art	*tmp;

	tmp = arts[i];
	arts[i] = arts[j];
	arts[j] = tmp;
}

int		partition(t_art **arts, int low, int high)
{
	int		i, j;
	int		idx;
	char	*pivot;

	i = low - 1;
	idx = rand() % (high - low + 1) + low;
	pivot = arts[idx]->name;
	for (j = low; j <= high - 1; j++)
	{
		if (strcmp(arts[j]->name, pivot) <= 0)
			swap(arts, ++i, j);
	}
	swap(arts, i + 1, high);
	return (i + 1);
}

void	quickSort(t_art **arts, int low, int high)
{
	int		pi;

	if (low < high)
	{
		pi = partition(arts, low, high);

		quickSort(arts, low, pi - 1);
		quickSort(arts, pi + 1, high);
	}
}

void	sortArts(struct s_art **arts)
{
	int		len;

	if (!arts)
		return ;
	len = 0;
	while (arts[len])
		len++;
	srand(time(NULL));
	quickSort(arts, 0, len - 1);
}
