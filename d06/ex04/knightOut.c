/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knightOut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 04:10:20 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/03 04:38:18 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "header.h"

/*
**	Utils
*/

int		getPos(uint64_t board) {
	return (getInitialPos(board));
}

void	getPosRowCol(uint64_t board, int *row, int *col) {
	*row = getPos(board) / 8;
	*col = getPos(board) % 8;
}

int		movesOut(int row, int col) {
	int	X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int	Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int	x, y, count = 0;

	for (int i = 0; i < 8; i++) {
		x = row + X[i]; y = col + Y[i];
		if (x < 0 || y < 0 || x > 8 || y > 8)
			count++;
	}
	return (count);
}

/*
**	Cache functions
*/

double	**initCache() {
	double	**cache = calloc(8, sizeof(double *));
	for (int i = 0; i < 8; i++)
		cache[i] = calloc(8, sizeof(double));
	return (cache);
}

void	fillCache(double **cache) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cache[i][j] = (double)movesOut(i, j) / 8;
		}
	}
}

void	printCache(double **cache) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%.2f ", cache[i][j]);
		}
		printf("\n");
	}
}

/*
**	Mandatory functions
*/

int		getInitialPos(uint64_t board) {
	int		pos = 0;
	while (!(board >> pos & 1)) pos++;
	return (pos);
}

double	knightOut(uint64_t board, int n) {
	double	**cache = initCache();
	fillCache(cache);
	printCache(cache);
	(void)board; (void)n;
	return (0.0);
}