/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ****** <************************>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:48:05 by ******            #+#    #+#             */
/*   Updated: 2022/07/31 13:32:16 by ******           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

void	printf_center(const char *format, ...);
void	center_grid(void);
void	print_grid(char (*grid)[3][3]);
int		get_int(const char *print);
int		get_user_input(char (*grid)[3][3], char player);

#endif
