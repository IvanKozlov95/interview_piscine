/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 03:17:09 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/03 20:46:14 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	 minPersons(int elements, int minPercentage) {
	int count = 2;
	double percent = 0.0;

	while (percent * 100 < minPercentage) {
		percent = 1.0 - (double)(pow((double)(elements - 1) / elements,
			(count * (count - 1)) / 2));
		count++;
	}
	return (count - 1);
}
