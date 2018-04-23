/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:25:23 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/23 16:20:56 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int		arts_len(t_art **arts)
{
	int		len;

	len = 0;
	while (arts[len])
		len++;
	return (len);
}

int		searchPrice(struct s_art **arts, int n, char *name)
{
	int		start;
	int		mid;
	int		cmp;
	int		end;

	if (!arts || !name)
		return (-1);

	start = 0;
	end = n - 1;
	if (strcmp(name, arts[start]->name) == 0)
		return (arts[start]->price);
	while (true)
	{
		mid = start + (end - start + 1) / 2;
		cmp = strcmp(name, arts[mid]->name);
		if (mid == end)
			break ;
		if (cmp > 0)
			start = mid;
		else if (cmp < 0)
			end = mid;
		else
			return (arts[mid]->price);
	}
	return (-1);
}