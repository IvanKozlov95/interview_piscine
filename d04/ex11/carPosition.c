/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:52:57 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/02 14:29:44 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int			carPosition(unsigned int parkingRow)
{
  if (parkingRow && !(parkingRow & (parkingRow - 1))) {
    return log2(parkingRow);
  }
  return -1;
}
