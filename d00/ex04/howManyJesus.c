/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:17:01 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/24 12:02:50 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void	tolowerstr(char *s, int l) {
	for (int i = 0; i < l; i++) {
		if (isalpha(s[i]))
			s[i] = tolower(s[i]);
	}
}

int		howManyJesus(char *bible, char *jesus) {
	int		i;
	char	*term;
	int		thatMany;
	int		term_len;
	int		book_len;

	thatMany = 0;
	term_len = strlen(jesus);
	book_len = strlen(bible);
	term = strdup(jesus);
	tolowerstr(term, term_len);
	tolowerstr(bible, book_len);
	i = -1;
	while (++i < book_len - term_len - 1) {
		while (!isalpha(bible[i])) i++;
		if (strncmp(bible + i, term, term_len) == 0)
			thatMany++;
		while (isalpha(bible[i])) i++;
	}
	free(term);
	return (thatMany);
}
