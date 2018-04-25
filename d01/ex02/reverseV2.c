/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:14:17 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/25 16:28:56 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
#include <stdlib.h>

/*
**	List functions
*/

t_item		*newNode(char *word) {
	t_item	*new;

	new = malloc(sizeof(t_item));
	new->word = word;
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

t_stack		*stackInit(void) {
	t_stack		*st;

	st = calloc(1, sizeof(t_stack));
	return (st);
}

void		*pop(struct s_stack *stack) {
	void	*res;

	if (!stack->item) return (NULL);
	res = stack->item->word;
	free(stack->item);
	stack->item = stack->item->next;
	return (res);
}

void		push(struct s_stack *stack, char *word) {
	listAdd(&stack->item, newNode(word));
}

/*
**	Reversed printing
*/

void		printReverseV2(struct s_node *lst) {
	char		*w;
	t_stack		*st;

	st = stackInit();
	while (lst) {
		push(st, lst->word);
		lst = lst->next;
	}
	while ((w = pop(st)))
		printf("%s%s", w, st->item ? " " : "");
}
