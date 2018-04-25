/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:30:33 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/25 16:54:38 by ikozlov          ###   ########.fr       */
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
	free(stack->item);
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
	int		read;
	size_t	len = 0;
	char	*msg = calloc(MSG_SIZE, sizeof(char));
	char	*buff = NULL;
	t_stack	*st = initStack();

	while (1) {
		printf("?: ");
		read = getline(&buff, &len, stdin);
		buff[read - 1] = '\0';
		if (strcmp(buff, UNDO) == 0) {
			i = pop(st);
			memset(msg + i, 0, MSG_SIZE - i);
		} else if (strcmp(buff, SEND) == 0) {
			destroyStack(&st);
			free(buff);
			break ;
		} else {
			push(st, i);
			if (i > 0) {
				strcat(msg, " ");
				i++;
			}
			strcat(msg, buff);
			i += strlen(buff);
		}
		free(buff); buff = NULL;
		printf("%s\n\n", msg);
	}
	return (msg);
}