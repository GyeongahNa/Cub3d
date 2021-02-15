/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertwallhit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 14:51:32 by gna               #+#    #+#             */
/*   Updated: 2020/09/05 10:38:38 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "../validitycheck/validitycheck.h"
#include "../header/keyinfo.h"
#include "../header/raycast.h"
#include "../header/mlx.h"

double	calxintercept(int columnid)
{
	double xintercept;

	xintercept = floor(g_player_x / g_tile_size) * g_tile_size;
	xintercept += ((g_rayinfo[columnid]->dir.israyfacingright == 1) ?
	(double)g_tile_size : 0);
	xintercept = ((g_rayinfo[columnid]->dir.israyfacingleft) ?
	xintercept - 1.0 : xintercept);
	return (xintercept);
}

double	calystep(int columnid)
{
	double	ystep;
	double	rayangle;

	rayangle = g_rayinfo[columnid]->rayangle;
	ystep = g_tile_size * tan(rayangle);
	ystep *= (((g_rayinfo[columnid]->dir.israyfacingup) &&
	(ystep > 0)) ? -1.0 : 1.0);
	ystep *= (((g_rayinfo[columnid]->dir.israyfacingdown) &&
	(ystep < 0)) ? -1.0 : 1.0);
	return (ystep);
}

void	savevertinfo(int columnid, int xintercept,
		int yintercept, int texnum)
{
	g_rayinfo[columnid]->vertcoord.washit = 1;
	g_rayinfo[columnid]->vertcoord.x = xintercept;
	g_rayinfo[columnid]->vertcoord.y = yintercept;
	g_rayinfo[columnid]->vertcoord.texture = texnum;
	g_rayinfo[columnid]->vertcoord.map_x =
	(int)(floor(xintercept / g_tile_size));
	g_rayinfo[columnid]->vertcoord.map_y =
	(int)(floor(yintercept / g_tile_size));
}

void	vertwallhit(int col, int **map, int start, int end)
{
	double	yinter;
	double	xinter;
	double	yst;
	double	xst;
	int	texnum;

	g_rayinfo[col]->vertcoord.washit = 0;
	xinter = calxintercept(col);
	yinter = g_player_y + (xinter - g_player_x) * tan(g_rayinfo[col]->rayangle);
	xst = g_tile_size *
	((g_rayinfo[col]->dir.israyfacingleft) ? -1.0 : 1.0);
	yst = calystep(col);
	while ((xinter > 0) && (xinter < g_window_width
	&& yinter > 0) && (yinter < g_window_height))
	{
		texnum = map[(int)floor((yinter / g_tile_size))]
			[(int)floor((xinter / g_tile_size))];
		if ((texnum > start) && (texnum < end))
		{
			savevertinfo(col, xinter, yinter, texnum);
			return ;
		}
		xinter += xst;
		yinter += yst;
	}
}
