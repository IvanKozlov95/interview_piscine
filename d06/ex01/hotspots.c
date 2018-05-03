/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 01:40:10 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/03 02:46:11 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

int		selectHotspots(struct s_hotspot **hotspots) {
	int			res = 1;
	int			covered;

	if (hotspots) {
		covered = hotspots[0]->radius;
		for (int i = 1; hotspots[i]; i++) {
			if (abs(hotspots[i]->pos - hotspots[i]->radius) >= covered) {
				res++;
				covered = hotspots[i]->pos + hotspots[i]->radius;
			}
			if (hotspots[i - 1]->pos + hotspots[i - 1]->radius >
				hotspots[i]->pos + hotspots[i]->radius)
				covered = hotspots[i]->pos + hotspots[i]->radius;
		}
	}
	return (res);
}
