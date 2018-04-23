/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:41:13 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/23 12:01:10 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

int		searchPrice(struct s_art **arts, char *name)
{
	int		i;

	if (!arts || !name)
		return (-1);
	i = 0;
	while (arts[i] != NULL && strcmp(arts[i]->name, name))
		i++;
	return (arts[i] ? arts[i]->price : -1);
}
