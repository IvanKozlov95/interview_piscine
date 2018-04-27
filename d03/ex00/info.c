/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:49:06 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/27 15:53:35 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <math.h>
#include <limits.h>
#include <stdlib.h>

int			getHeight(t_node *root) {
	if (!root || (!root->left && !root->right)) return (0);
	return (fmax(getHeight(root->left), getHeight(root->right)) + 1);
}

int			getDepth(t_node *root) {
	if (!root) return (0);
	return (fmax(getDepth(root->left), getDepth(root->right)) + 1);
}

void		setMinMaxCount(t_node *root, t_info *info) {
	if (!root)
		return ;
	info->elements++;
	if (root->value < info->min) info->min = root->value;
	if (root->value > info->max) info->max = root->value;
	setMinMaxCount(root->left, info);
	setMinMaxCount(root->right, info);
}

int			checkIfBalanced(t_node *root) {
	if (!root) return (1);
	if (abs(getDepth(root->left) - getDepth(root->right)) <= 1 &&
		checkIfBalanced(root->left) && checkIfBalanced(root->right))
			return (1);
	return (0);
}

int			checkIfBST(t_node *root, int min, int max) {
	if (!root) return (1);
	if (root->value < min || root->value > max) return (0);
	return (checkIfBST(root->left, min, root->value)
		&& checkIfBST(root->right, root->value, max));
}

/*
**	Mandatory function
*/

t_info		getInfo(struct s_node *root) {
	t_info	info;

	info.min = INT_MAX; info.max = INT_MIN;
	info.elements = 0;
	setMinMaxCount(root, &info);
	info.height = getHeight(root);
	info.isBalanced = checkIfBalanced(root);
	info.isBST = checkIfBST(root, info.min, info.max);
	return (info);
}
