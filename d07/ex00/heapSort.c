/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:03:14 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/05 13:41:43 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int   cmp(struct s_art *a, struct s_art *b) {
  return a->price - b->price;
}

void  swap(struct s_art **a, int i, int j) {
  struct s_art *tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

void  heapify(struct s_art **a, int i, int n) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  int largest = l < n && cmp(a[l], a[i]) > 0 ? l : i;
  largest = r < n && cmp(a[r], a[largest]) > 0 ? r : largest;
  if (largest != i) {
    swap(a, i, largest);
    heapify(a, largest, n);
  }
}

void  heapSort(struct s_art **masterpiece, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(masterpiece, i, n);
  }

  for (int i = n - 1; i >= 0; i--) {
    swap(masterpiece, 0, i);
    heapify(masterpiece, 0, i);
  }
}