/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:52:57 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/02 13:03:01 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			carPosition(unsigned int parkingRow)
{
  int		ret;

  ret = -1;
  if (!(parkingRow & (parkingRow - 1)))
    while (parkingRow) {
      ret++; parkingRow >>= 1;
    }
  return (ret);
}
