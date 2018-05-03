/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 01:40:10 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/03 02:55:53 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

int		selectHotspots(struct s_hotspot **hotspots) {
	int			res = 1;
	int			covered = 0;

	if (hotspots) {
		for (int i = 1; hotspots[i]; i++) {
			if (abs(hotspots[i]->pos - hotspots[i]->radius) >= covered) {
				covered = hotspots[i]->pos + hotspots[i]->radius;
				res++;
			}
			if (covered > hotspots[i]->pos + hotspots[i]->radius)
				covered = hotspots[i]->pos + hotspots[i]->radius;
		}
	}
	return (res);
}
