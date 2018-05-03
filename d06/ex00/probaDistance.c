/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 01:25:48 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/03 01:34:24 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	probaDistance(int dist, int *locations, int n) {
	int		res = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (locations[j] - locations[i] > dist) {
				res += n - j;
				break ;
			}
		}
	}
	return ((double)res / (n * (n - 1) / 2));
}
