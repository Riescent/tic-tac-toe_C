/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <************************>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:27:56 by ******            #+#    #+#             */
/*   Updated: 2022/07/31 14:54:27 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "win.h"
#include "io.h"
#include "stdbool.h"
#include <stdlib.h>

void	draw(char (*grid)[3][3])
{
	int		y;
	int		x;
	bool	not_draw;

	not_draw = false;
	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			if ((*grid)[y][x] != 'X' && (*grid)[y][x] != 'O')
			{
				not_draw = true;
				break ;
			}
			x++;
		}
		y++;
	}
	if (not_draw)
		return ;
	printf_center("Draw\n");
	exit(0);
}

void	end(char (*grid)[3][3], char player)
{
	horizontal_win(grid, player);
	vertical_win(grid, player);
	diagonal_win(grid, player);
	draw(grid);
}
