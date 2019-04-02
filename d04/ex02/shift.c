/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:56:26 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/02 11:56:28 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <string.h>

char		*twoscomp(char *a)
{
  int i;
  char twoscomp[8] = {0};

  strcpy(twoscomp + 1, a);
	for (i = 5; i >= 0; i--)
    if (a[i] == '1') break ;
  if (i == -1) {
    twoscomp[0] = '1';
    return strdup(twoscomp);
  }
  for (int j = i - 1; j >= 0; j--)
    twoscomp[j + 1] = a[j] == '0' ? '1' : '0';
	return strdup(twoscomp + 1);
}

char		*rightShift(char *bin, int k)
{
	for (int i = 5; i >= 0; i--) {
    if ((i - k) < 6) {
      bin[i - k] = bin[i];
      bin[i] = '1';
    }
  }
  printf("%s\n", bin);
	return (bin);
}

char		*leftShift(char *bin, int k)
{
	for (int i = 0; i < 6; i++) {
    if ((i + k) < 6) {
      bin[i + k] = bin[i];
    } else {
      bin[i] = '0';
    }
  }
	return (bin);
}

int			toInt(char *bits)
{
	int		ret;
	int		sign;
  int   power = 32;

	ret = 0;
	sign = *bits == '1' ? -1 : 1;
  bits = sign > 0 ? bits : twoscomp(bits);
  for (int i = 0; i < 6; i++)
    ret = ret * 2 + bits[i] - '0';
	return (ret * sign);
}