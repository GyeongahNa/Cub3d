/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendersprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:57:05 by gna               #+#    #+#             */
/*   Updated: 2020/09/06 08:04:01 by gna              ###   ########.fr       */
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

int			getcenter(int num)
{
	int	center;

	if (g_sprtinfo[num]->start > 0 &&
		g_sprtinfo[num]->end < g_num_rays - 1)
		center = g_sprtinfo[num]->start +
		0.5 * g_sprtinfo[num]->wallheight;
	else if (g_sprtinfo[num]->start == 0 &&
		g_sprtinfo[num]->end == g_num_rays - 1)
		center = g_window_width / 2;
	else if ((g_sprtinfo[num]->end - g_sprtinfo[num]->start)
		/ g_sprtinfo[num]->wallheight > 0.98)
		center = g_sprtinfo[num]->start +
		0.5 * g_sprtinfo[num]->wallheight;
	else if (g_sprtinfo[num]->start == 0 &&
		g_sprtinfo[num]->end < g_num_rays - 1)
		center = g_sprtinfo[num]->end -
		0.5 * g_sprtinfo[num]->wallheight;
	else if (g_sprtinfo[num]->start > 0 &&
		g_sprtinfo[num]->end == g_num_rays - 1)
		center = g_sprtinfo[num]->start +
		0.5 * g_sprtinfo[num]->wallheight;
	else
		center = 0;
	return (center);
}

void		renderpart(int columnid, double dist, int color)
{
	int			texx;
	int			texy;
	double		wallheight;
	int			start;
	int			k;

	texx = caltexx(columnid);
	wallheight = g_rayinfo[columnid]->wallheight;
	start = (int)(floor(g_middleline - wallheight / 2));
	k = start;
	dist = g_rayinfo[columnid]->raydistance * 0.003;
	while (k < start + wallheight)
	{
		if (k >= 0 && k < g_window_height)
		{
			texy = (k - start) / wallheight * TEXHEIGHT;
			color = g_texture[gettexture(columnid)]
				[texx + TEXWIDTH * texy];
			if (dist > 1)
				color = shadow(color, dist);
			g_image_data[columnid + g_window_width * k] = color;
		}
		k++;
	}
}

void		renderfrontwall(void)
{
	int	columnid;

	columnid = 0;
	while (columnid < g_num_rays)
	{
		if ((g_rayinfo[columnid]->wassprite == 0) &&
		(g_rayinfo[columnid]->map_x != 0) &&
		(g_rayinfo[columnid]->map_y != 0) &&
		(g_rayinfo[columnid]->map_x != g_map_num_cols - 1) &&
		(g_rayinfo[columnid]->map_y != g_map_num_rows - 1))
		{
			renderpart(columnid, 0, 0);
		}
		columnid++;
	}
}

void		renderheight(int i, int rowstart, int num, int texx)
{
	int			j;
	int			texy;
	double		dist;
	int			color;
	int			rowend;

	j = rowstart;
	rowend = (int)(rowstart + g_sprtinfo[num]->wallheight);
	while (j < rowend)
	{
		texy = (j - rowstart) /
			g_sprtinfo[num]->wallheight * TEXHEIGHT;
		if (i >= 0 && i <= g_window_width - 1 &&
			j >= 0 && j <= g_window_height - 1)
		{
			dist = distancepoints(g_sprtinfo[num]->node_x,
			g_sprtinfo[num]->node_y, g_player_x, g_player_y) * 0.003;
			color = g_texture[4][texx + TEXWIDTH * texy];
			if (dist > 1)
				color = shadow(color, dist);
			if (color != 0)
				g_image_data[i + g_window_width * j] = color;
		}
		j++;
	}
}

void		renderwidth(int colstart, int colend, int num)
{
	int		texx;
	int		rowstart;
	int		i;

	i = colstart;
	while (i < colend)
	{
		texx = (i - colstart) / g_sprtinfo[num]->wallheight * TEXWIDTH;
		rowstart = (int)(g_middleline - g_sprtinfo[num]->wallheight * 0.5);
		renderheight(i, rowstart, num, texx);
		i++;
	}
}
