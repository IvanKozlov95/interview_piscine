/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:17:01 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/24 09:25:56 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include <stdio.h>

int		howManyJesus(char *bible, char *jesus) {
	int		thatMany;
	int		term_len;
	int		book_len;
	int		i;

	i = -1;
	thatMany = 0;
	term_len = strlen(jesus);
	book_len = strlen(bible);
	while (++i < book_len - term_len - 1) {
		while (!isalpha(bible[i])) i++;
		if (strncmp(bible + i, jesus, term_len) == 0)
			thatMany++;
		// printf("Here\n");
		while (bible[i] != ' ' && bible[i] != '\n') i++;
	}
	return (thatMany);
}
