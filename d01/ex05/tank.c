/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:49:28 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/25 22:53:54 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
#include <stdlib.h>

/*
**	List functions
*/

t_elem		*newNode(int energy) {
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	new->energy = energy;
	new->next = NULL;
	return (new);
}

void	listAdd(t_elem **alst, t_elem *new)
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

int			pop(struct s_stack *stack) {
	int		res;

	if (!stack->elem) return (-1);
	res = stack->elem->energy;
	free(stack->elem);
	stack->elem = stack->elem->next;
	stack->sum -= res;
	return (res);
}

void		push(struct s_stack *stack, int energy) {
	stack->sum += energy;
	if (!stack->elem) {
		stack->elem = newNode(energy);
		return ;
	}
	listAdd(&stack->elem, newNode(energy));
}

/*
**	Stack managing functions
*/

void		addStack(t_tank *t) {
	t->n++;
	t->stacks = realloc(t->stacks, t->n * sizeof(t_stack));
	t->stacks[t->n - 1] = calloc(1, sizeof(t_stack));
	t->stacks[t->n - 1]->sum = 0;
}

void		removeStack(t_tank *t) {
	t->n--;
	free(t->stacks[t->n]);
	if (t->n == 0) {
		free(t->stacks);
		t->stacks = NULL;
	} else {
		t->stacks = realloc(t->stacks, t->n * sizeof(t_stack));
	}
}

t_stack		*currentStack(t_tank *t) {
	if (t->n == 0) return (NULL);
	return (t->stacks[t->n - 1]);
}

/*
**	Tank functions
*/

struct		s_tank *initTank(void) {
	return (calloc(1, sizeof(sizeof(t_tank))));
}

void		tankPush(struct s_tank *tank, int energy) {
	t_stack		*c;

	if (!tank || !energy) return ;
	c = currentStack(tank);
	if (!c || c->sum + energy > 1000) {
		addStack(tank);
	}
	push(currentStack(tank), energy);
}

int			tankPop(struct s_tank *tank) {
	t_stack	*c;
	int		res = 0;

	if (tank  && (c = currentStack(tank))) {
		res = pop(c);
		if (c->sum == 0) removeStack(tank);
	}
	return (res);
}