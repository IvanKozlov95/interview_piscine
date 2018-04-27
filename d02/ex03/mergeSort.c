/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:18:56 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/26 18:00:56 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	Utils
*/

int		getSize(t_player **players) {
	int		len = -1;

	while (players[++len]) ;
	return (len);
}

/*
**	Mandatory functions
*/

void		merge(t_player **players, int l, int m, int r) {
	int			i, j, k;
	int			n1 = m - l + 1;
	int			n2 = r - m;
	t_player	*left[n1];
	t_player	*right[n2];

	for (i = 0; i < n1; i++) left[i] = players[l + i];
	for (j = 0; j < n2; j++) right[j] = players[m + 1 + j];

	i = 0; j = 0; k = l;
	while (i < n1 && j < n2)
		if (left[i]->score >= right[j]->score)
			players[k++] = left[i++];
		else
			players[k++] = right[j++];

	while (i < n1) players[k++] = left[i++];
	while (j < n2) players[k++] = right[j++];
}

void		sort(t_player **players, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		sort(players, l, m);
		sort(players, m + 1, r);
		merge(players, l, m, r);
	}
}

struct s_player **mergeSort(struct s_player **players) {
	sort(players, 0, getSize(players) - 1);
	return (players);
}