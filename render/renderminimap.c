/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderminimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:03:06 by gna               #+#    #+#             */
/*   Updated: 2020/09/03 12:03:11 by gna              ###   ########.fr       */
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

void	renderblock(int i, int j, int color)
{
	int k;
	int l;

	k = j * g_tile_size * MINIMAP_SCALE_FACTOR;
	while (k < (j * g_tile_size + g_tile_size) * MINIMAP_SCALE_FACTOR)
	{
		l = i * g_tile_size * MINIMAP_SCALE_FACTOR;
		while (l < (i * g_tile_size + g_tile_size) * MINIMAP_SCALE_FACTOR)
		{
			g_image_data[k + g_window_width * l] = color;
			l++;
		}
		k++;
	}
}

void	rendermap(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_map_num_rows)
	{
		j = 0;
		while (j < g_map_num_cols)
		{
			if (g_imap[i][j] == 0)
				renderblock(i, j, 0);
			else if (g_imap[i][j] == 1)
				renderblock(i, j, 255);
			else if (g_imap[i][j] == 2)
				renderblock(i, j, 255 * 256);
			j++;
		}
		i++;
	}
}

void	renderrays(int i, int j, double k)
{
	int		columnid;
	double	wallhitx;
	double	wallhity;

	columnid = 0;
	while (columnid < g_num_rays)
	{
		wallhitx = g_rayinfo[columnid]->wallhitx;
		wallhity = g_rayinfo[columnid]->wallhity;
		k = 0;
		while (k < MINIMAP_SCALE_FACTOR *
				sqrt((g_player_x - wallhitx) * (g_player_x - wallhitx)
				+ (g_player_y - wallhity) * (g_player_y - wallhity)))
		{
			i = g_player_x * MINIMAP_SCALE_FACTOR +
				cos(g_rayinfo[columnid]->rayangle) * k;
			j = g_player_y * MINIMAP_SCALE_FACTOR +
					sin(g_rayinfo[columnid]->rayangle) * k;
			g_image_data[i + g_window_width * j] =
			255 * 256 * 256 + 102 * 256 + 51;
			k = k + 0.05;
		}
		columnid++;
	}
}
