/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:30:55 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/02 16:54:33 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int longestSequence(unsigned int parkingRow) {
  int ret = 0;
  while (parkingRow) {
    parkingRow &= parkingRow << 1;
    ret++;
  }
  return ret;
}
