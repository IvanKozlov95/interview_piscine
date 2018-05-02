/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:51:42 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/05/02 15:32:21 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void	bestPricesRec(int size, double *prices, double current, double *max) {
	if (size == 0) {
		*max < current ? *max = current : (void)0;
		return ;
	} else {
		for (int i = 1; i <= size; i++)
			bestPricesRec(size - i, prices, current + prices[i], max);
	}
}

double	bestPrice(int pizzaSize, double *prices) {
	double	best = 0;
	bestPricesRec(pizzaSize, prices, 0, &best);
	return (best);
}
	