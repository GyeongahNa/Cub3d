/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:30:58 by gna               #+#    #+#             */
/*   Updated: 2020/09/05 22:31:05 by gna              ###   ########.fr       */
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

int	update(void)
{
	double	movestep;
	double	new_x;
	double	new_y;
	double	movestep2;

	movestep = g_walkdirection * g_movespeed;
	movestep2 = g_lrwalkdirection * g_movespeed;
	g_rotationangle += g_turndirection * g_rotationspeed;
	new_x = g_player_x + cos(g_rotationangle) * movestep
	- cos(M_PI / 2 - g_rotationangle) * movestep2;
	new_y = g_player_y + sin(g_rotationangle) * movestep
	+ sin(M_PI / 2 - g_rotationangle) * movestep2;
	if (g_imap[(int)(new_y / g_tile_size)][(int)(new_x / g_tile_size)] == 0 ||
	(g_imap[(int)(new_y / g_tile_size)][(int)(new_x / g_tile_size)] == 2))
	{
		g_player_x = new_x;
		g_player_y = new_y;
	}
	return (0);
}
