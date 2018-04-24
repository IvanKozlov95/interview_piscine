/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:10:48 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/24 15:15:43 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
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
**	Dictionary functions
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
						char *key, int value)
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

int				dictSearch(struct s_dict *dict, char *key)
{
	int		i;
	t_item	*list;

	i = hash(key) % dict->capacity;
	list = dict->items[i];
	while (list) {
		if (strcmp(list->key, key) == 0)
			return (list->value);
		list = list->next;
	}
	return (-1);
};

char			*dictPrintHeader(struct  s_dict *dict, int *size)
{
	char	*h;
	char	*header;
	int		i, len;
	t_item	*temp;

	i = 0; len = 0;
	for (i = 0; i < dict->capacity; i++) {
		temp = dict->items[i];
		while (temp) 
		{
			len += strlen(temp->key) + 1;
			temp = temp->next;
		}
	}
	len++;
	*size = len;
	header = calloc(1, len + 1);
	header[0] = '<';
	h = header + 1;
	for (i = 0; i < dict->capacity; i++) {
		temp = dict->items[i];
		while (temp) 
		{
			len = strlen(temp->key);
			strncpy(h, temp->key, len);
			h[len] = ',';
			temp = temp->next;
			h += len + 1;
		}
	}
	*(h - 1) = '>';
	return header;
}

/*
**	Utils
*/

char			*copyword(char *s, int i) {
	int		j;
	char	*res;

	j = i;
	while (isalpha(s[j])) j++;
	res = malloc(j - i + 1);
	strncpy(res, s + i, j - i + 1);
	res[j - i] = '\0';
	return (res);
}

char			*init_compress(int book_len, t_dict *dict, int *pos) {
	char	*res;
	char	*header;
	int		header_len;

	header_len = 0;
	header = dictPrintHeader(dict, &header_len);
	res = malloc(sizeof(char) * (book_len + header_len + 1));
	strcpy(res, header);
	*pos = header_len;
	(void)pos;
	return (res);
}

/*
**	Mandatory functions
*/

char			*compress(char *book, struct s_dict *dict) {
	int		i;
	int		j;
	int		book_len;
	int		search;
	char	*key;
	char	*compress;

	key = NULL;
	book_len = strlen(book);
	j = 0; i = 0;
	compress = init_compress(book_len, dict, &j);
	while (book[i]) {
		while (!isalpha(book[i])) {
			compress[j] = book[i];
			j++; i++;
		}
		if (key) free(key);
		key = copyword(book, i);
		search = dictSearch(dict, key);
		if (search > 0) {
			compress[j++] = '@';
			compress[j++] = search + 1;
		} else {
			search = strlen(key);
			strncpy(compress + j, book + i, search);
			j += search;
		}
		while (isalpha(book[i])) i++;
	}
	compress[j] = '\0';
	return (compress);
}
