/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <************************>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:29:14 by ******            #+#    #+#             */
/*   Updated: 2022/07/31 14:06:53 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

char	*grid_from_number(char (*grid)[3][3], int number)
{
	int	number_test;
	int	y;
	int	x;

	number_test = 1;
	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			if (number == number_test)
				return (&((*grid)[y][x]));
			number_test++;
			x++;
		}
		y++;
	}
	printf("ERROR\nfile: %s\nline: %i\nint number == %i\n",
		__FILE__, __LINE__, number);
	exit(1);
}

void	play(char (*grid)[3][3], char player)
{
	int		user_input;
	char	*box;

	user_input = get_user_input(grid, player);
	box = grid_from_number(grid, user_input);
	*box = player;
}
