/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:25:04 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/26 14:12:01 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
#include <stdlib.h>

/*
**	Group functions
*/

t_group		*newGroup(t_stone *stone) {
	t_group		*res;

	res = calloc(1, sizeof(t_group));
	res->first = stone;
	res->last = stone;
	res->size = stone->size;
	return (res);
}

void		insertStone(t_group **g, t_stone *s) {
	t_group		*tmp;

	if (*g == NULL)
		*g = newGroup(s);
	else {
		tmp = *g;
		while (tmp->next) {
			if (tmp->size == s->size) {
				tmp->last->next = s;
				tmp->last = s;
				return ;
			}
			tmp = tmp->next;
		}
		tmp->next = newGroup(s);
	}
}

t_group		*getGroups(t_stone *stones) {
	t_group		*res = NULL;

	while (stones) {
		insertStone(&res, stones);
		stones = stones->next;
	}
	return (res);
}

void		swapGroups(t_group *g1, t_group *g2) {
	int			s;
	t_stone		*f, *l;

	f = g1->first; l = g1->last; s = g1->size;
	g1->first = g2->first; g1->last = g2->last; g1->size = g2->size;
	g2->first = f; g2->last = l; g2->size = s;
}

t_stone		*mergeGroups(t_group *g) {
	t_stone		*res = NULL, *tmp;

	while (g) {
		if (!res)
			res = g->first;
		else
			tmp->next = g->first;
		tmp = g->last;
		g = g->next;
	}
	tmp->next = NULL;
	return (res);
}

void		deleteGroups(t_group *g) {
	t_group	*tmp = g, *next;

	while (tmp) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

/*
**	Mandatory function
*/

void		sortStones(struct s_stone **stone) {
	int			swap;
	t_group		*p1, *p2 = NULL;
	t_group		*groups = getGroups(*stone);

	swap = 1;
	while (swap) {
		swap = 0;
		p1 = groups;
		while (p1->next != p2) {
			if (p1->size > p1->next->size) {
				swapGroups(p1, p1->next);
				swap = 1;
			}
			p1 = p1->next;
		}
		p2 = p1;
	}
	*stone = mergeGroups(groups);
	deleteGroups(groups);
}
