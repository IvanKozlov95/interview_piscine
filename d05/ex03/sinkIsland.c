/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 20:42:56 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/02 20:52:24 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sinkIsland(int **map, int row, int col) {
	if (row < 0 || col < 0 || !map[row] || map[row][col] == -1
		|| map[row][col] == 0)
		return ;
	map[row][col] = 0;
	sinkIsland(map, row, col - 1);
	sinkIsland(map, row, col + 1);
	sinkIsland(map, row - 1, col);
	sinkIsland(map, row + 1, col);
}
