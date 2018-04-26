/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:57:54 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/25 23:18:20 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stddef.h>

char *NthLastCity(t_city *city, int n)
{
	static int	g;
	static char	*res = NULL;

	if (!city) {
		g = 0;
		res = NULL;
	} else {
		NthLastCity(city->next, n);
		if (g == n) {
			res = city->name;
		}
		g++;
	}
	return (res);
}
