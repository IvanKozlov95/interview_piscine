/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:17:01 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/24 22:54:39 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int		hash_slide(int hash, int s, int e) {
	return (hash - s + e);
}

int		hash(char *str, int s, int e) {
	int hash;

	hash = 0;
	for (int i = s; i < e; i++) {
		hash += str[i];
	}
	return (hash);
}

void	tolowerstr(char *s, int l) {
	for (int i = 0; i < l; i++) {
		if (isalpha(s[i]))
			s[i] = tolower(s[i]);
	}
}

int		howManyJesus(char *bible, char *jesus) {
	int		i, j;
	int		thatMany;
	int		h1, h2;
	char	*term;
	int		term_len;
	int		book_len;

	thatMany = 0;
	term_len = strlen(jesus);
	book_len = strlen(bible);
	term = strdup(jesus);
	tolowerstr(term, term_len);
	tolowerstr(bible, book_len);
	h1 = hash(term, 0, term_len);
	h2 = hash(bible, 0, term_len);
	j = 0; i = term_len;
	while (i < book_len) {
		if (h1 == h2 && strncmp(bible + j, term, term_len) == 0)
			thatMany++;
		h2 = hash_slide(h2, bible[j], bible[i]);
		i++; j++;
	}
	return (thatMany);
}
