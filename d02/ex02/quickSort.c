/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:45:11 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/26 16:11:34 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*
**	Utils
*/

int		getSize(t_player **players) {
	int		len = -1;

	while (players[++len]) ;
	return (len);
}

/*
**	Standart quick sort part
*/

int		cmp(const void *a, const void *b) {
	t_player	*p1, *p2;

	p1 = *(t_player **)a;
	p2 = *(t_player **)b;
	return (p2->score - p1->score);
}

/*
**	My quick sort part
*/

void	swap(t_player **players, int i, int j)
{
	t_player	*tmp;

	tmp = players[i];
	players[i] = players[j];
	players[j] = tmp;
}

int		partition(t_player **players, int low, int high)
{
	int			i, j;
	t_player	*pivot;

	i = low - 1;
	pivot = players[high];
	for (j = low; j <= high - 1; j++)
		if (players[j]->score >= pivot->score)
			swap(players, ++i, j);
	swap(players, i + 1, high);
	return (i + 1);
}

void	quickSortRec(t_player **players, int low, int high) {
	if (low < high) {
		int pi = partition(players, low, high);
		quickSortRec(players, low, pi - 1);
		quickSortRec(players, pi + 1, high);
	}
}

void	quickSort(struct s_player **players) {
	int			len = getSize(players);

	srand(time(NULL));
	quickSortRec(players, 0, len - 1);
	// qsort(players, len, sizeof(t_player *), cmp);
}
