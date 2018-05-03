/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 21:25:53 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/02 21:38:39 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "header.h"

void	swap(char *s, int i, int j) {
	char	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

void	permute(char *s, int l, int r, t_dict *dict) {
	if (l == r && dictSearch(dict, s) < 0) {
		dictInsert(dict, s, 1);
		printf("%s\n", s);
	} else {
		for (int i = l; i <= r; i++) {
			swap(s, l, i);
			permute(s, l + 1, r, dict);
			swap(s, l, i);
		}
	}
}

void	printUniquePermutations(char *str) {
	if (str) {
		t_dict	*d = dictInit(strlen(str));
		permute(str, 0, strlen(str) - 1, d);
	}
}