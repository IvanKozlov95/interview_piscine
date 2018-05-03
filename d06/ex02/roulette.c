/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 02:49:53 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/03 03:16:14 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
	if (nbGame < 0 || firstDollarsBet == 0)
		return (0.0);
	if (firstDollarsBet >= dollarsWanted)
		return (1.0);
	return ((18 * probabilityWin(firstDollarsBet * 2, dollarsWanted, nbGame - 1) +
		probabilityWin(firstDollarsBet / 2, dollarsWanted, nbGame - 1)) / 37);
}