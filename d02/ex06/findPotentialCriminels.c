/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:24:25 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/26 22:14:31 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>
#include <stdio.h>

/*
**	Utils
*/

int			getMax(t_criminal **criminals, int *i) {
	int		max;

	for (*i = 0; criminals[*i]; (*i)++) {
		if (criminals[*i]->description > max)
			max = criminals[*i]->description;
	}
	return (max);
}

/*
**	Sotring function
*/

void		countSort(t_criminal **a, int n, int exp) {
	int			i, j;
	t_criminal	*output[n];
	int			count[10] = {0};

	for (i = 0; i < n; i++) count[(a[i]->description / exp) % 10]++;
	for (i = 1; i < 10; i++) count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) {
		j = (a[i]->description / exp) % 10;
		output[count[j] - 1] = a[i];
		count[j]--;
	}
	for (i = 0; i < n; i++) a[i] = output[i];
}

/*
**	Binary search
*/

int			binarySearch(t_criminal **a, int l, int r, int key) {
	if (r > l) {
		int mid = (l + r) / 2;
		if (a[mid]->description == key)
			return (mid);
		else if (key < a[mid]->description)
			return (binarySearch(a, l, mid - 1, key));
		else
			return (binarySearch(a, mid + 1, r, key));
	}
	return (-1);
}

/*
**	Mandatory functions
*/

int			getDescription(struct s_info *info)
{
	if (!info) return 0;
	return (info->gender * 1000000 +
		info->height * 100000 +
		info->hairColor * 10000 +
		info->eyeColor * 1000 +
		info->glasses * 100 +
		info->tattoo * 10 +
		info->piercing * 1);
}

void		sortCriminals(struct s_criminal **criminals) {
	int		len;
	int		max = getMax(criminals, &len);

	for (int i = 1; max / i > 0; i *= 10)
		countSort(criminals, len, i);
}

t_criminal	**findPotentialCriminals(struct s_criminal **criminals, struct s_info *info) {
	int			n, i;
	t_criminal	**res = NULL;
	int			desc, left, right;

	getMax(criminals, &n);
	desc = getDescription(info);
	i = binarySearch(criminals, 0, n - 1, desc);
	if (i > 0) {
		left = i; right = i;
		while (left - 1 >= 0 && criminals[left - 1]->description == desc)
			left--;
		while (right + 1 < n && criminals[right + 1]->description == desc)
			right++;
		res = malloc(sizeof(t_criminal *) * (right - left + 2));
		for (i = 0; i <= right - left; i++)
			res[i] = criminals[left + i];
		res[i] = NULL;
	}
	return (res);
}
