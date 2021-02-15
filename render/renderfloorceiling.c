/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderfloorceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 11:46:46 by gna               #+#    #+#             */
/*   Updated: 2020/09/03 11:48:18 by gna              ###   ########.fr       */
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

void	renderfloor(void)
{
	int	columnid;
	double	wallheight;
	double	k;

	columnid = 0;
	while (columnid < g_num_rays)
	{
		wallheight = g_rayinfo[columnid]->wallheight;
		k = (int)(g_middleline - wallheight / 2 + wallheight - 2);
		while (k < g_window_height)
		{
			if (k >= 0)
				g_image_data[columnid + g_window_width * (int)k] =
				g_f_r * 256 * 256 + g_f_g * 256 + g_f_b;
			k = k + 1;
		}
		columnid++;
	}
}

void	renderceiling(void)
{
	int	columnid;
	double	wallheight;
	double	k;

	columnid = 0;
	while (columnid < g_num_rays)
	{
		wallheight = g_rayinfo[(int)columnid]->wallheight;
		k = 0;
		while (k < (int)(g_middleline - wallheight / 2 + 2))
		{
			if ((k >= 0) && (k < g_window_height))
				g_image_data[columnid + g_window_width * (int)k] =
				g_c_r * 256 * 256 + g_c_g * 256 + g_c_b;
			k++;
		}
		columnid++;
	}
}
