/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:25:53 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/26 14:39:00 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>

void insertionSort(struct s_player **players) {
	int			i, j;
	t_player	*player;

	i = 0;
	while (players[++i] != NULL) {
		player = players[i];
		j = i;
		while (--j >= 0 && players[j]->score < player->score) {
			players[j + 1] = players[j];
		}
		players[j + 1] = player;
	}
}
