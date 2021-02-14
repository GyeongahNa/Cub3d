/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderwall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:17:41 by gna               #+#    #+#             */
/*   Updated: 2020/09/06 11:27:01 by gna              ###   ########.fr       */
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

int		caltexx(int columnid)
{
	int	texx;

	texx = (g_rayinfo[columnid]->washorzhit == 1) ?
	(int)((fmod(g_rayinfo[columnid]->wallhitx, g_tile_size) /
	g_tile_size * TEXWIDTH)) :
	(int)((fmod(g_rayinfo[columnid]->wallhity, g_tile_size) /
	g_tile_size * TEXWIDTH));
	return (texx);
}

int		shadow(int color, double dist)
{
	double	r;
	double	g;
	double	b;

	r = (double)(color / 256 / 256) * (1 / (dist));
	g = (double)(color / 256 % 256) * (1 / (dist));
	b = (double)(color % 256) * (1 / (dist));
	color = (int)r * (256 * 256) + (int)g * 256 + (int)b;
	return (color);
}

int		gettexture(int columnid)
{
	double	wallhitx;
	double	wallhity;

	wallhitx = g_rayinfo[columnid]->wallhitx;
	wallhity = g_rayinfo[columnid]->wallhity;
	if (fmod(wallhity, g_tile_size) == g_tile_size - 1)
		return (0);
	else if (fmod(wallhity, g_tile_size) == 0)
		return (2);
	else if (fmod(wallhitx, g_tile_size) == g_tile_size - 1)
		return (3);
	else if (fmod(wallhitx, g_tile_size) == 0)
		return (1);
	return (0);
}

void	wallrendering(double d, int col, int k, int start)
{
	int		texx;
	int		texy;
	double	wallheight;

	while (col < g_num_rays)
	{
		texx = caltexx(col);
		wallheight = g_rayinfo[col]->wallheight;
		start = (int)(floor(g_middleline - wallheight / 2));
		k = start;
		d = g_rayinfo[col]->raydistance * 0.003;
		while (k < start + wallheight)
		{
			if (k >= 0 && k < g_window_height)
			{
				texy = (k - start) / wallheight * TEXHEIGHT;
				g_image_data[col + g_window_width * k] = (d <= 1 ? g_texture\
				[gettexture(col)][texx + TEXWIDTH * texy] : shadow(
				g_texture[gettexture(col)][texx + TEXWIDTH * texy], d));
			}
			k++;
		}
		col++;
	}
}
