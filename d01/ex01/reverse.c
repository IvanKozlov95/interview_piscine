/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:50:59 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/25 13:58:43 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

void	printReverseRec(t_node *list, int first) {
	if (!list) return ;
	printReverseRec(list->next, 0);
	printf("%s%s", list->word, first ? "" : " ");
}

void	printReverse(struct s_node *lst) {
	printReverseRec(lst, 1);
}
