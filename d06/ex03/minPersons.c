/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 03:17:09 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/03 03:49:06 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int		minPersons(int elements, int minPercentage) {
	return (ceil(
			sqrt(
				2 * elements *
				log(
					1 / (1 - (double)minPercentage / 100)
				)
			)
		) + 1
	);
}