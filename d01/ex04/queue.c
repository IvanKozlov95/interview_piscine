/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:26:00 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/25 18:32:38 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>
#include <stdio.h>

/*
** List functions
*/

t_node			*newNode(char *word) {
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->message = word;
	new->next = NULL;
	return (new);
}

/*
**	Queue functions
*/

struct s_queue	*queueInit(void) {
	return ((t_queue *)calloc(1, sizeof(t_queue)));
}

char			*dequeue(struct s_queue *queue) {
	char	*msg;
	t_node	*tmp;

	if (isEmpty(queue)) return (NULL);
	msg = queue->first->message;
	tmp = queue->first;
	queue->first = queue->first->next;
	if (!queue->first) queue->last = NULL;
	free(tmp);
	return (msg);
}

void enqueue(struct s_queue *queue, char *message) {
	t_node	*new = newNode(message);

	if (isEmpty(queue)) {
		queue->first = new;
		queue->last = new;
		return ;
	}
	queue->last->next = new;
	queue->last = new;
}

char *peek(struct s_queue *queue) {
	return (!isEmpty(queue) ? queue->first->message : NULL);
}

int isEmpty(struct s_queue *queue) {
	return !(queue && queue->first);
}
