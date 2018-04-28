/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 22:44:55 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/27 23:08:48 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_node **a, t_node **b) {
	t_node	*tmp = *a;
	t_node	*tmpLeft = (*b)->left;
	t_node	*tmpRight = (*b)->right;

	*a = *b;
	if (tmp->left == (*b)) {
		(*b)->left = tmp;
		(*b)->right = tmp->right;
	} else {
		(*b)->right = tmp;
		(*b)->left = tmp->left;
	}
	tmp->left = tmpLeft;
	tmp->right = tmpRight;
}

int		heap(t_node **root) {
	int		res = 0;

	if (*root) {
		res = 1;
		if ((*root)->right && (*root)->value < (*root)->right->value)
			swap(root, &(*root)->right);
		if ((*root)->left && (*root)->value < (*root)->left->value)
			swap(root, &(*root)->left);
		res += heap(&(*root)->right);
		res += heap(&(*root)->left);
	}
	return (res);
}

void saveTheSequoia(struct s_node **root)
{
	if (!root) return;

	int n = heap(root);
	for (int i = 0; i < n - 1; i++)
		heap(root);
}
