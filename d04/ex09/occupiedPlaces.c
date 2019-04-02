/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:40:20 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/02 12:41:34 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int occupiedPlaces(unsigned int parkingRow) {
  int   count;

  while (parkingRow) {
    parkingRow &= parkingRow - 1;
    count++;
  }
  return count;
}
