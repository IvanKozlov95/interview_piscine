/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:16:12 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/27 15:46:06 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>
#include <limits.h>

t_node		*newNode(int value) {
	t_node	*new = calloc(1, sizeof(t_node));
	new->value = value;
	return (new);
}

t_node		*createTreeUtil(int arr[], int *idx, int key, int min, int max, int n) {
	t_node	*root = NULL;

	if (*idx < 0) return (NULL);
	if (key > min && key < max) {
		root = newNode(key);
		(*idx)--;
		if (*idx < n) {
			root->left = createTreeUtil(arr, idx, arr[*idx], min, key, n);
			root->right = createTreeUtil(arr, idx, arr[*idx], key, max, n);
		}
	}
	return (root);
}

t_node		*createBSTRec(int arr[], int l, int r) {
	int		m = (l + r) / 2;
	t_node	*root;

	if (l > r) return (NULL);
	root = newNode(arr[m]);
	root->left = createBSTRec(arr, l, m - 1);
	root->right = createBSTRec(arr, m + 1, r);
	return (root);
}

t_node		*createBST(int *arr, int n) {
	// int		idx = n - 1;
	// return (createTreeUtil(arr, &idx, arr[idx], INT_MIN, INT_MAX, n));
	return (createBSTRec(arr, 0, n - 1));
}
