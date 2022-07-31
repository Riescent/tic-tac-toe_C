/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <************************>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:32:44 by ******            #+#    #+#             */
/*   Updated: 2022/07/31 13:58:52 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include <stdlib.h>

void	win(char player)
{
	printf_center("Player %c won the game!\n", player);
	exit(0);
}

void	horizontal_win(char (*grid)[3][3], char player)
{
	int	counter;

	counter = 0;
	while (counter < 3)
	{
		if ((*grid)[counter][0] == (*grid)[counter][1]
			&& (*grid)[counter][1] == (*grid)[counter][2])
			win(player);
		counter++;
	}
}

void	vertical_win(char (*grid)[3][3], char player)
{
	int	counter;

	counter = 0;
	while (counter < 3)
	{
		if ((*grid)[0][counter] == (*grid)[1][counter]
			&& (*grid)[1][counter] == (*grid)[2][counter])
			win(player);
		counter++;
	}
}

void	diagonal_win(char (*grid)[3][3], char player)
{
	if ((*grid)[2][0] == (*grid)[1][1] && (*grid)[1][1] == (*grid)[0][2])
		win(player);
	if ((*grid)[0][0] == (*grid)[1][1] && (*grid)[1][1] == (*grid)[2][2])
		win(player);
}
