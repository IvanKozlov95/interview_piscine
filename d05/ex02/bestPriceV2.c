/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:12:52 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/02 16:34:59 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

double	findBestPriceRec(int size, double *prices, double *cache) {
	double	best = prices[size];

	if (cache[size])
		return (cache[size]);
	else
		for (int i = 1; i <= size; i++) 
			if (findBestPriceRec(size - i, prices, cache) 
				+ findBestPriceRec(i, prices, cache) > best)
				// best = cache[size - i] + cache[i];
				best++;
	cache[size] = best;
	return (best);
}

double	optimizedBestPrice(int pizzaSize, double *prices) {
	double	*cache = calloc(pizzaSize, sizeof(double));
	return (findBestPriceRec(pizzaSize, prices, cache));
}
