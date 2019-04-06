/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:47:54 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/05 19:08:41 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

struct s_node *newNode(int val) {
  struct s_node *new = calloc(1, sizeof(struct s_node));
  new->value = val;
  return new;
}

struct s_node *createBST(int *arr, int n) {
  return createBSTRec(arr, 0, n - 1);
}

struct s_node *createBSTRec(int *arr, int s, int e) {
  if (e < s) return NULL;

  int mid = s + (e - s) / 2;
  struct s_node *node = newNode(arr[mid]);
  node->left = createBSTRec(arr, s, mid - 1);
  node->right = createBSTRec(arr, mid + 1, e);
  return node;
}
