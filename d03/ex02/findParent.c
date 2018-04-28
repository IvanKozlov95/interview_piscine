/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:16:38 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/27 22:26:00 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
** List functions
*/

t_item	*newNode(void *node) {
	t_item	*new;

	new = malloc(sizeof(t_item));
	new->node = node;
	new->next = NULL;
	return (new);
}

/*
**	Queue functions
*/

struct s_queue	*queueInit(void) {
	return ((t_queue *)calloc(1, sizeof(t_queue)));
}

void			queueDestroy(t_queue *queue) {
	while (!isEmpty(queue))
		dequeue(queue);
	free(queue);
}

void			*dequeue(struct s_queue *queue) {
	t_item	*tmp;
	t_node	*res;

	if (isEmpty(queue)) return (NULL);
	res = queue->first->node;
	tmp = queue->first;
	queue->first = queue->first->next;
	if (!queue->first) queue->last = NULL;
	free(tmp);
	return (res);
}

void			enqueue(struct s_queue *queue, void *content) {
	t_item	*new = newNode(content);

	if (isEmpty(queue)) {
		queue->first = new;
		queue->last = new;
		return ;
	}
	queue->last->next = new;
	queue->last = new;
}

void			*denqueueBack(t_queue *queue) {
	t_item	*tmp;
	t_node	*res;

	if (isEmpty(queue)) return (NULL);
	tmp = queue->first;
	while (tmp && tmp->next != queue->last) tmp = tmp->next;
	res = queue->last->node;
	free(queue->last);
	queue->last = tmp;
	if (queue->last)
		queue->last->next = NULL;
	else
		queue->first = NULL;
	return (res);
}

void			*peek(struct s_queue *queue) {
	return (!isEmpty(queue) ? queue->first->node : NULL);
}

int				isEmpty(struct s_queue *queue) {
	return !(queue && queue->first);
}

/*
**	BFS
*/

int				findPath(t_node *root, t_queue *q, char *name) {
	t_node		**kids;

	if (!root) return (0);
	enqueue(q, root);
	if (!strcmp(root->name, name))
		return (1);
	kids = root->children;
	while (*kids) {
		if (findPath(*kids, q, name))
			return (1);
		kids++;
	}
	denqueueBack(q);
	return (0);
}

/*
**	Mandatory function
*/

t_node		*findParent(struct s_node *root, char *firstSpecies, char *secondSpecies) {
	t_node	*res = NULL;
	t_queue	*q1 = queueInit();
	t_queue	*q2 = queueInit();

	findPath(root, q1, firstSpecies);
	findPath(root, q2, secondSpecies);
	printf("Here %d %d \n", isEmpty(q1), isEmpty(q2));
	while (!isEmpty(q1) && !isEmpty(q2)) {
		if (peek(q1) != peek(q2)) break ;
		res = dequeue(q1);
		dequeue(q2);
	}
	return (res);
}
