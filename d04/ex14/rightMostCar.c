/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightMostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:36:30 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/02 16:26:32 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int rightmostCar(unsigned int parkingRow) {
  int ret = 0;
  while (parkingRow && !(parkingRow & 1)) {
    parkingRow >>= 1; 
    ret++;
  }
  return ret - !parkingRow;
}
