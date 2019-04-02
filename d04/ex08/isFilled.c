/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:31:25 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/02 12:38:40 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int isFilled(unsigned int parkingRow) {
  return ~(parkingRow & (parkingRow + 1));
}