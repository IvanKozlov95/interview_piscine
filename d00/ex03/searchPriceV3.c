/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:54:15 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/23 17:55:41 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	List functions
*/

t_item			*ft_lstlast(t_item *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void			ft_lstaddback(t_item **alst, t_item *new)
{
	if (*alst == NULL)
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
}

/*
**	Mandatory functions
*/

size_t			hash(char *input)
{
	return (1);
}

struct s_dict		*dictInit(int capacity)
{
	t_dict		*res;

	res = malloc(sizeof(t_dict));
	res->items = malloc(sizeof(t_item *) * capacity);
	res->capacity = capacity;
	return (res);
}

int					dictInsert(struct s_dict *dict,
						char *key, struct s_art *value)
{
	int		i;
	t_item	*item;

	i = hash(key) % dict->capacity;
	item = mallloc(sizeof(t_item));
	if (!item)
		return (0);
	item->key = key;
	item->value = value;
	
}
struct s_art *dictSearch(struct s_dict *dict, char *key); //find