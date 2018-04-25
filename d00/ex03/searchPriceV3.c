/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:54:15 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/24 17:17:29 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
** Utils
*/

int		arts_len(t_art **arts)
{
	int		len;

	len = 0;
	while (arts[len])
		len++;
	return (len);
}

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
	size_t		hash;
	char		c;

	hash = 5381;
	while ((c = *input++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}

struct s_dict	*dictInit(int capacity)
{
	t_dict		*res;
	size_t		size;

	res = malloc(sizeof(t_dict));
	size = sizeof(t_item *) * capacity;
	res->items = malloc(size);
	bzero(res->items, size);
	res->capacity = capacity;
	return (res);
}

int				dictInsert(struct s_dict *dict,
						char *key, struct s_art *value)
{
	int		i;
	t_item	*item;

	i = hash(key) % dict->capacity;
	item = malloc(sizeof(t_item));
	if (!item)
		return (0);
	item->key = key;
	item->value = value;
	item->next = NULL;
	ft_lstaddback(&dict->items[i], item);
	return (i);
}

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
	int		i;
	t_item	*list;

	i = hash(key) % dict->capacity;
	list = dict->items[i];
	while (list) {
		if (strcmp(list->value->name, key) == 0)
			return (list->value);
		list = list->next;
	}
	return (NULL);
}

void		find(t_dict *d, char *key) {
	t_art	*item;

	item = dictSearch(d, key);
	if (item)
		printf("Art: name \'%s\' price %d\n", item->name, item->price);
	else
		printf("Art not found. Key: %s\n", key);
}