/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getspriteinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 08:57:58 by gna               #+#    #+#             */
/*   Updated: 2020/09/06 00:14:54 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "../validitycheck/validitycheck.h"
#include "../header/keyinfo.h"
#include "../header/raycast.h"
#include "../header/mlx.h"

int	checksprite(void)
{
	int	columnid;
	int	issprite;

	columnid = 0;
	issprite = 0;
	while (columnid < g_num_rays)
	{
		if (g_imap[g_rayinfo[columnid]->map_y][g_rayinfo[columnid]->map_x] == 2)
			issprite = 1;
		columnid++;
	}
	return (issprite == 1 ? 1 : -1);
}

int	findnearest(double min, int mincol)
{
	int	columnid;
	int	map_x;
	int	map_y;
	double	node_x;
	double	node_y;

	columnid = 0;
	while (columnid < g_num_rays)
	{
		if (g_rayinfo[columnid]->wassprite == 1)
		{
			map_x = g_rayinfo[columnid]->map_x;
			map_y = g_rayinfo[columnid]->map_y;
			node_x = g_tile_size * 0.5 + map_x * g_tile_size;
			node_y = g_tile_size * 0.5 + map_y * g_tile_size;
			if (distancepoints(node_x, node_y, g_player_x, g_player_y) < min)
			{
				min = distancepoints(node_x, node_y, g_player_x, g_player_y);
				mincol = columnid;
			}
		}
		columnid++;
	}
	return (mincol);
}

void	getbasicinfo(int nearest, int cnt)
{
	int	map_x;
	int	map_y;
	double	projectionplane;
	double	raydistance;
	double	wallheight;

	map_x = g_rayinfo[nearest]->map_x;
	map_y = g_rayinfo[nearest]->map_y;
	g_sprtinfo[cnt]->map_x = map_x;
	g_sprtinfo[cnt]->map_y = map_y;
	g_sprtinfo[cnt]->node_x = g_tile_size * 0.5 + g_tile_size * map_x;
	g_sprtinfo[cnt]->node_y = g_tile_size * 0.5 + g_tile_size * map_y;
	projectionplane = (g_window_width / 2) / tan(FOV_ANGLE / 2);
	raydistance = distancepoints(g_player_x, g_player_y,
			g_sprtinfo[cnt]->node_x, g_sprtinfo[cnt]->node_y);
	wallheight = ((g_tile_size / raydistance) * projectionplane);
	g_sprtinfo[cnt]->wallheight = wallheight;
}

void	getinfo(int nearest, int cnt)
{
	int	columnid;
	int	x;
	int	y;

	x = g_rayinfo[nearest]->map_x;
	y = g_rayinfo[nearest]->map_y;
	columnid = 0;
	while (columnid < g_num_rays)
	{
		if ((g_rayinfo[columnid]->map_x == x)
				&& (g_rayinfo[columnid]->map_y == y))
		{
			g_sprtinfo[cnt]->start = columnid;
			break ;
		}
		columnid++;
	}
	while ((columnid < g_num_rays) && (g_rayinfo[columnid]->map_x == x)
			&& (g_rayinfo[columnid]->map_y == y))
		columnid++;
	if (columnid == 0)
		columnid = columnid + 1;
	g_sprtinfo[cnt]->end = columnid - 1;
}

int	savespriteinfo(void)
{
	int	sprite;
	int	nearest;
	int	cnt;

	cnt = 0;
	sprite = 1;
	cpymap();
	while (sprite == 1)
	{
		raycast(g_cpmap, 0, 3);
		sprite = checksprite();
		if (sprite == 1)
		{
			nearest = findnearest(2000000000000, 0);
			getbasicinfo(nearest, cnt);
			getinfo(nearest, cnt);
			g_cpmap[(g_rayinfo[nearest]->map_y)]\
				[(g_rayinfo[nearest]->map_x)] = 0;
			cnt++;
		}
	}
	return (cnt);
}
