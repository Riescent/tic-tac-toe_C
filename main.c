/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <************************>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:47:15 by ******            #+#    #+#             */
/*   Updated: 2022/07/31 12:59:45 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "game.h"
#include "end.h"

void	initialsize_grid(char (*grid)[3][3])
{
	int	y;
	int	x;
	int	square;

	square = 1;
	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			(*grid)[y][x] = square + 48;
			square++;
			x++;
		}
		y++;
	}
}

int	main(void)
{
	char	grid[3][3];

	initialsize_grid(&grid);
	print_grid(&grid);
	while (1)
	{
		play(&grid, 'X');
		print_grid(&grid);
		end(&grid, 'X');
		play(&grid, 'O');
		print_grid(&grid);
		end(&grid, 'O');
	}
}
