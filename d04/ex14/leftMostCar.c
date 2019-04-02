/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfetMostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:36:30 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/02 14:50:25 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int leftmostCar(unsigned int parkingRow) {
  int ret = 0;
  while (parkingRow > 1) {
    parkingRow >>= 1; 
    ret++;
  }
  return parkingRow ? ret : -1;
}
