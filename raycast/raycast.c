/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:39:59 by gna               #+#    #+#             */
/*   Updated: 2020/09/05 10:30:49 by gna              ###   ########.fr       */
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

void	direction(int columnid)
{
	double rayangle;

	rayangle = (g_rayinfo[columnid]->rayangle);
	g_rayinfo[columnid]->dir.israyfacingdown =
	((rayangle > 0) && (rayangle < M_PI)) ? 1 : 0;
	g_rayinfo[columnid]->dir.israyfacingup =
	(g_rayinfo[columnid]->dir.israyfacingdown == 1) ? 0 : 1;
	g_rayinfo[columnid]->dir.israyfacingright =
	((rayangle < 0.5 * M_PI) || (rayangle > 1.5 * M_PI)) ? 1 : 0;
	g_rayinfo[columnid]->dir.israyfacingleft =
	(g_rayinfo[columnid]->dir.israyfacingright == 1) ? 0 : 1;
}

void	findwallhit2(int columnid,
		double horzhitdistance, double verthitdistance)
{
	double	distanceprojectionplane;

	distanceprojectionplane = (g_window_width / 2) / tan(FOV_ANGLE / 2);
	g_rayinfo[columnid]->wallheight = ((g_tile_size /
	g_rayinfo[columnid]->raydistance) * distanceprojectionplane);
	g_rayinfo[columnid]->texnum = (horzhitdistance <= verthitdistance) ?
	g_rayinfo[columnid]->horzcoord.texture :
	g_rayinfo[columnid]->vertcoord.texture;
	g_rayinfo[columnid]->map_x = (horzhitdistance <= verthitdistance) ?
	g_rayinfo[columnid]->horzcoord.map_x : g_rayinfo[columnid]->vertcoord.map_x;
	g_rayinfo[columnid]->map_y = (horzhitdistance <= verthitdistance) ?
	g_rayinfo[columnid]->horzcoord.map_y : g_rayinfo[columnid]->vertcoord.map_y;
	g_rayinfo[columnid]->wassprite = (g_rayinfo[columnid]->texnum) == 2 ? 1 : 0;
}

void	findwallhit(int columnid)
{
	double	horzhitdistance;
	double	verthitdistance;
	double	rayangle;

	rayangle = g_rayinfo[columnid]->rayangle;
	horzhitdistance = ((g_rayinfo[columnid]->horzcoord.washit == 1) ?
	distancepoints(g_player_x, g_player_y, g_rayinfo[columnid]->horzcoord.x,
	g_rayinfo[columnid]->horzcoord.y) : 200000);
	verthitdistance = ((g_rayinfo[columnid]->vertcoord.washit == 1) ?
	distancepoints(g_player_x, g_player_y, g_rayinfo[columnid]->vertcoord.x,
	g_rayinfo[columnid]->vertcoord.y) : 200000);
	g_rayinfo[columnid]->washorzhit =
	((horzhitdistance <= verthitdistance) ? 1 : 0);
	g_rayinfo[columnid]->wallhitx =
	((horzhitdistance <= verthitdistance) ?
	g_rayinfo[columnid]->horzcoord.x : g_rayinfo[columnid]->vertcoord.x);
	g_rayinfo[columnid]->wallhity = ((horzhitdistance <= verthitdistance) ?
	g_rayinfo[columnid]->horzcoord.y : g_rayinfo[columnid]->vertcoord.y);
	g_rayinfo[columnid]->raydistance = ((horzhitdistance <= verthitdistance) ?
	horzhitdistance : verthitdistance);
	g_rayinfo[columnid]->raydistance *= (cos(rayangle - g_rotationangle));
	findwallhit2(columnid, horzhitdistance, verthitdistance);
}

void	raycast(int **map, int start, int end)
{
	int	columnid;
	double	rayangle;

	columnid = 0;
	rayangle = g_rotationangle - (FOV_ANGLE / 2);
	while (columnid < g_num_rays)
	{
		rayangle = normalizeangle(rayangle);
		g_rayinfo[columnid]->rayangle = rayangle;
		direction(columnid);
		horzwallhit(columnid, map, start, end);
		vertwallhit(columnid, map, start, end);
		findwallhit(columnid);
		rayangle += FOV_ANGLE / (double)(g_num_rays);
		columnid++;
	}
}
