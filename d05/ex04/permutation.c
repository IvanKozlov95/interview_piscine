/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 20:55:29 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/02 20:59:05 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	swap(char *s, int i, int j) {
	char	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

void	permute(char *s, int l, int r) {
	if (l == r)
		printf("%s\n", s);
	else
		for (int i = l; i <= r; i++) {
			swap(s, l, i);
			permute(s, l + 1, r);
			swap(s, l, i);
		}
}

void	printPermutations(char *str) {
	if (str) permute(str, 0, strlen(str) - 1);
}
