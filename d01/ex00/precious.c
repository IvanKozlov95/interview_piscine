/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:58:58 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/25 13:33:04 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
**	List functions
*/

t_node		*newNode(char c) {
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->c = c;
	new->next = new;
	new->prev = new;
	return (new);
}

void	listInsert(t_node **l, t_node *new) {
	if (*l == NULL)
		*l = new;
	else {
		new->next = (*l)->prev->next;
		new->prev = (*l)->prev;
		(*l)->prev->next = new;
		(*l)->prev = new;
	}
}

/*
**	Utils
*/

t_node		*initPrecious(void) {
	int		i;
	int		len;
	t_node	*l;

	l = NULL;
	len = strlen(CS);
	for (i = 0; i < len; i++) {
		listInsert(&l, newNode(CS[i]));
	}
	return (l);
}

void		printList(t_node *l) {
	t_node	*start;

	start = l;
	int		i = 0;
	while (l) {
		printf("#%d. Node: %c, next: %c, prev: %c\n",
			i, l->c, l->next->c, l->prev->c);
		i++;
		l = l->next;
		if (start == l) break ;
	}
}

/*
**	Mandatory function
*/

char		*precious(int *text, int size) {
	int		tmp;
	int		step;
	char	*res;
	t_node	*list;

	list = initPrecious();
	res = calloc(size + 1, sizeof(char));
	for (int i = 0; i < size; i++) {
		tmp = text[i];
		step = tmp > 0 ? -1 : 1;
		for (int j = tmp; j != 0; j += step) {
			list = tmp > 0 ? list->next : list->prev;
		}
		res[i] = list->c;
	}
	return (res);
}
