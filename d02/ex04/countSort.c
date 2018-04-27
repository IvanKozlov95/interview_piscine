/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:07:07 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/26 19:03:24 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>

#define RANGE 15

void	countSort(unsigned char *utensils, int n) {
	int				i;
	int				count[RANGE] = {0};
	unsigned char	*sorted = calloc(n, sizeof(unsigned char));

	for (i = 0; i < n; i++)
		count[utensils[i] - 1]++;
	for (i = 1; i < RANGE; i++)
		count[i] += count[i - 1];
	for (i = 0; i < n; i++) {
		sorted[count[utensils[i] - 1]] = utensils[i];
		count[utensils[i] - 1]--;
	}
	for (i = 0; i < n; i++)
		utensils[i] = sorted[i];
	free(sorted);
}
