/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:30:33 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/25 16:00:54 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
**	List functions
*/

t_item		*newNode(int idx) {
	t_item	*new;

	new = malloc(sizeof(t_item));
	new->idx = idx;
	new->next = NULL;
	return (new);
}


void	listAdd(t_item **alst, t_item *new)
{
	if (!alst) return ;
	if (!*alst) {
		*alst = new;
		return ;
	}

	new->next = *alst;
	*alst = new;
}

/*
**	Stack functions
*/

t_stack		*initStack(void) {
	t_stack		*st;

	st = calloc(1, sizeof(t_stack));
	return (st);
}

void		destroyStack(t_stack **stack) {
	t_stack		*tmp;
	t_item		*item;

	tmp = *stack;
	while (tmp->item) {
		item = tmp->item->next;
		free(tmp->item);
		tmp->item = item;
	}
	free(tmp);
	*stack = NULL;
}

int			pop(struct s_stack *stack) {
	int		res;

	if (!stack->item) return (-1);
	res = stack->item->idx;
	stack->item = stack->item->next;
	return (res);
}

void		push(struct s_stack *stack, int idx) {
	listAdd(&stack->item, newNode(idx));
}

/*
**	Console function
*/

char		*console(void) {
	int		i = 0;
	char	*msg = calloc(MSG_SIZE, sizeof(char));
	char	buff[MSG_SIZE] = {0};
	t_stack	*st = initStack();

	(void)st;
	(void)msg;
	while (1) {
		printf("?: ");
		scanf("%[^\n]%*c", buff);
		if (strcmp(buff, UNDO) == 0) {
			i = pop(st);
			memset(msg + i + 1, 0, MSG_SIZE - i);
			// i++;
		} else if (strcmp(buff, SEND) == 0) {
			destroyStack(&st);
			return (msg);
		} else {
			push(st, i);
			strcat(msg, buff);
			strcat(msg, " ");
			i += strlen(buff);
		}
		printf("%s\n\n", msg);
	}
	return (NULL);
}