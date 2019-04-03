/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piano.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:58:55 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/02 17:08:20 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>

int	**pianoDecompress(struct s_bit *bit, int l)
{
  int   **piano = calloc(bit->n, sizeof(int *));
  int   *bits = bit->arr;

  for (int i = 0; i < bit->n; i++) {
    piano[i] = calloc(l, sizeof(int));
    int n = bits[i];
    for (int j = 0; n; j++, n >>= 1) {
      piano[i][j] = n & 1;
    }
  }
  return piano;
}