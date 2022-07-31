/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <************************>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:31:05 by ******            #+#    #+#             */
/*   Updated: 2022/07/31 14:35:37 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
//print_center
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdarg.h>
//!
#define LINE "-------------\n"

void	printf_center(const char *format, ...)
{
	va_list			args;
	char			print_me[1000];
	struct winsize	window_size;
	int				spaces_to_write;
	int				counter;

	va_start(args, format);
	vsnprintf(print_me, sizeof(print_me) / sizeof(print_me[0]), format, args);
	va_end(args);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
	spaces_to_write = window_size.ws_col / 2 - strlen(print_me) / 2;
	counter = 0;
	while (counter < spaces_to_write)
	{
		printf(" ");
		counter++;
	}
	printf("%s", print_me);
}

void	center_grid(void)
{
	struct winsize	window_size;
	int				counter;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
	counter = 0;
	while (counter < window_size.ws_row / 2 - 4)
	{
		printf("\n");
		counter++;
	}
}

void	print_grid(char (*grid)[3][3])
{
	int	counter;

	printf("\e[1;1H\e[2J");
	center_grid();
	counter = 2;
	while (counter >= 0)
	{
		printf_center(" %c | %c | %c \n", (*grid)[counter][0],
			(*grid)[counter][1], (*grid)[counter][2]);
		if (counter > 0)
		{
			printf_center("%s", LINE);
		}
		counter--;
	}
	printf("\n");
}

int	get_int(const char *print)
{
	int	return_integer;

	printf_center("%s", print);
	if (!scanf("%i", &return_integer))
	{
		printf_center("An error occured, make sure you input an integer.\n");
		while (return_integer != '\n' && return_integer != EOF)
			return_integer = getchar();
		return_integer = get_int(print);
	}
	return (return_integer);
}

int	get_user_input(char (*grid)[3][3], char player)
{
	int		return_value;
	char	print[24];
	char	*box;

	sprintf(print, "It is player %c's turn: ", player);
	return_value = get_int(print);
	while (return_value < 1 || return_value > 9)
	{
		printf_center("Needs to be between 1 and 9\n");
		return_value = get_int(print);
	}
	box = grid_from_number(grid, return_value);
	if (*box == 'X' || *box == 'O')
	{
		printf_center("%c is already placed on box %i\n",
			*box, return_value);
		return_value = get_int(print);
	}
	return (return_value);
}
