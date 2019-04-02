/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:55:46 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/02 12:01:27 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*getXor(char *a, char *b)
{
	for (int i = 0; i < 6; i++)
    a[i] = (a[i] != b[i]) + '0';
	return (a);
}

int		toInt(char *bits)
{
	int	ret;

	ret = 0;
	while (*bits)
	{
		ret = ret * 2 + *bits - '0';
		bits += 1;
	}
	return (ret);
}
