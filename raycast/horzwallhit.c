/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horzwallhit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 09:15:22 by gna               #+#    #+#             */
/*   Updated: 2020/09/05 10:34:18 by gna              ###   ########.fr       */
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

double	calyintercept(int columnid)
{
	double	yintercept;

	yintercept = floor(g_player_y / g_tile_size) * g_tile_size;
	yintercept += ((g_rayinfo[columnid]->dir.israyfacingdown == 1) ?
				(double)g_tile_size : 0);
	yintercept = ((g_rayinfo[columnid]->dir.israyfacingup == 1) ?
				yintercept - 1.0 : yintercept);
	return (yintercept);
}

double	calxstep(int columnid)
{
	double xstep;
	double rayangle;

	rayangle = (g_rayinfo[columnid]->rayangle);
	xstep = g_tile_size / tan(rayangle);
	xstep *= (((g_rayinfo[columnid]->dir.israyfacingleft) && xstep > 0) ?
			-1 : 1);
	xstep *= (((g_rayinfo[columnid]->dir.israyfacingright) && xstep < 0) ?
			-1 : 1);
	return (xstep);
}

void	savehorzinfo(int columnid, int xint, int yint, int texnum)
{
	g_rayinfo[columnid]->horzcoord.washit = 1;
	g_rayinfo[columnid]->horzcoord.x = xint;
	g_rayinfo[columnid]->horzcoord.y = yint;
	g_rayinfo[columnid]->horzcoord.texture = texnum;
	g_rayinfo[columnid]->horzcoord.map_x = (int)(xint / g_tile_size);
	g_rayinfo[columnid]->horzcoord.map_y = (int)(yint / g_tile_size);
}

void	horzwallhit(int columnid, int **map, int start, int end)
{
	double	yinter;
	double	xinter;
	double	yst;
	double	xst;
	int	texnum;

	g_rayinfo[columnid]->horzcoord.washit = 0;
	yinter = calyintercept(columnid);
	xinter = g_player_x + (yinter - g_player_y) /
		(double)tan(g_rayinfo[columnid]->rayangle);
	yst = g_tile_size * ((g_rayinfo[columnid]->dir.israyfacingup) ? -1 : 1);
	xst = calxstep(columnid);
	while ((xinter > 0) && (xinter < g_window_width) &&
			(yinter > 0) && (yinter < g_window_height))
	{
		texnum = map[(int)floor((yinter / g_tile_size))]
			[(int)floor((xinter / g_tile_size))];
		if ((texnum > start) && (texnum < end))
		{
			savehorzinfo(columnid, xinter, yinter, texnum);
			return ;
		}
		xinter += xst;
		yinter += yst;
	}
}
