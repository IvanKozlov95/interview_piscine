/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:56:30 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/02 11:56:30 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void  negate(char *n) {
  for (int i = 0; i < 4; i++) {
    n[i] = n[i] == '0' ? '1' : '0';
  }
}

char *getAnd(char *a, char *b) {
  char and[5] = {0};

  if (a[0] == '~') negate(a++);
  if (b[0] == '~') negate(b++);
  for (int i = 0; i < 4; i++) {
    and[i] = '0' + (a[i] == '1' && b[i] == '1');
  }
  return (strdup(and));
}
 
char *getOr(char *a, char *b) {
  char and[5] = {0};

  if (a[0] == '~') negate(a++);
  if (b[0] == '~') negate(b++);
  for (int i = 0; i < 4; i++) {
    and[i] = '0' + (a[i] == '1' || b[i] == '1');
  }
  return (strdup(and));;
}

int			toInt(char *bits)
{
	int		ret;

	ret = 0;
	while (*bits)
	{
		ret = ret * 2 + *bits - '0';
		bits += 1;
	}
	return (ret);
}