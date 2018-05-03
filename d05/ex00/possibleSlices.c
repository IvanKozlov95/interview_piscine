/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:15:31 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/02 21:13:32 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void	printRec(t_array *a, int n) {
	if (n == 0) {
		arrayPrint(a);
		free(a);
	} else {
		for (int i = 1; i <= n; i++) {
			t_array *clone = arrayClone(a);
			arrayAppend(clone, i);
			printRec(clone, n - i);
		}
	}
}

void	printPossibleSlices(int pizzaSize) {
	t_array		*a = arrayInit();
	printRec(a, pizzaSize);
}
