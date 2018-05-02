/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:51:42 by ivankozlov        #+#    #+#             */
/*   Updated: 2018/05/02 14:05:43 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

double	bestPricesRec(int size, double *prices, double max) {
}

double	bestPrice(int pizzaSize, double *prices) {
	bestPricesRec(pizzaSize, prices, 0);
}