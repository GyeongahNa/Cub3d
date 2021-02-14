/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderlifebar_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:10:56 by gna               #+#    #+#             */
/*   Updated: 2020/09/06 11:40:18 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../header/raycast_bonus.h"

void	lifecheck(void)
{
	if (g_imap[(int)(floor(g_player_y / g_tile_size))]\
	[(int)((floor)(g_player_x / g_tile_size))] == 2)
	{
		if (g_life > 0)
			g_life = g_life - 1;
	}
}

void	renderlifebar(double wstart, double wend, double hstart, double hend)
{
	double	x;
	double	y;

	x = wstart;
	while (x < wend)
	{
		y = hstart;
		while (y < hend)
		{
			g_image_data[(int)x + g_window_width * (int)y] = 255 * 256 * 256;
			y++;
		}
		x++;
	}
	x = wstart;
	while (x < (wstart + ((wend - wstart) / 100) * g_life))
	{
		y = hstart;
		while (y < hend)
		{
			g_image_data[(int)x + g_window_width * (int)y] = 255 * 256;
			y++;
		}
		x++;
	}
}
