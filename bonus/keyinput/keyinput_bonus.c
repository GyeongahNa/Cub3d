/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 09:38:18 by gna               #+#    #+#             */
/*   Updated: 2020/09/06 10:56:03 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "../validitycheck/validitycheck_bonus.h"
#include "../header/keyinfo_bonus.h"
#include "../header/raycast_bonus.h"
#include "../header/mlx_bonus.h"

void	react_movekey(int key)
{
	if (key == W)
		g_walkdirection = +1;
	else if (key == S)
		g_walkdirection = -1;
	else if (key == A)
		g_lrwalkdirection = -1;
	else if (key == D)
		g_lrwalkdirection = +1;
}

void	react_updownkey(int key)
{
	int	new_middle;

	if (key == D_ARROW)
	{
		new_middle = g_middleline - g_window_height / 40;
		if ((new_middle > 0) && (new_middle < g_window_height))
			g_middleline = new_middle;
	}
	else if (key == U_ARROW)
	{
		new_middle = g_middleline + g_window_height / 40;
		if ((new_middle > 0) && (new_middle < g_window_height))
			g_middleline = new_middle;
	}
}

int		ft_keypress(int key)
{
	if (key == ESC)
		destroywindow();
	react_movekey(key);
	react_updownkey(key);
	if (key == L_ARROW)
		g_turndirection = -1;
	else if (key == R_ARROW)
		g_turndirection = +1;
	return (0);
}

int		ft_keyrelease(int key)
{
	if (key == L_ARROW)
		g_turndirection = 0;
	else if (key == R_ARROW)
		g_turndirection = 0;
	else if (key == W)
		g_walkdirection = 0;
	else if (key == S)
		g_walkdirection = 0;
	else if (key == A)
		g_lrwalkdirection = 0;
	else if (key == D)
		g_lrwalkdirection = 0;
	return (0);
}

int		processinput(void)
{
	mlx_hook(g_win_ptr, KEYPRESS, KEYPRESSMASK, ft_keypress, (void *)(0));
	mlx_hook(g_win_ptr, KEYRELEASE, KEYRELEASEMASK, ft_keyrelease, (void *)(0));
	mlx_hook(g_win_ptr, REDCROSS, KEYRELEASEMASK, destroywindow, (void *)(0));
	return (0);
}
