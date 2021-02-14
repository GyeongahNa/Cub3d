/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 14:01:14 by gna               #+#    #+#             */
/*   Updated: 2020/09/06 11:22:34 by gna              ###   ########.fr       */
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

void	getwindowsize(void)
{
	int	original_width;
	int	original_height;

	while (g_map[g_map_num_rows] != 0)
		g_map_num_rows++;
	while (g_map[0][g_map_num_cols] != '\0')
		g_map_num_cols++;
	original_width = g_tile_size * g_map_num_cols;
	original_height = g_tile_size * g_map_num_rows;
	if (g_r_width < original_width || g_r_height < original_height)
	{
		g_tile_size = ((g_r_width / g_map_num_cols < g_r_height /
		g_map_num_rows) ? g_r_width / g_map_num_cols :
		g_r_height / g_map_num_rows);
		g_window_width = g_map_num_cols * g_tile_size;
		g_window_height = g_map_num_rows * g_tile_size;
	}
	else
	{
		g_window_width = original_width;
		g_window_height = original_height;
	}
	g_num_rays = g_window_width;
	g_middleline = g_window_height / 2;
}

void	getfirstposition(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_map[i] != 0)
	{
		j = 0;
		while (g_map[i][j] != '\0')
		{
			if (g_map[i][j] == 'N' || g_map[i][j] == 'S' ||
				g_map[i][j] == 'W' || g_map[i][j] == 'E')
			{
				g_player_x = 0.5 * g_tile_size + j * g_tile_size;
				g_player_y = 0.5 * g_tile_size + i * g_tile_size;
				break ;
			}
			j++;
		}
		i++;
	}
}

double	matchangle(char dir)
{
	if (dir == 'N')
		return (1.5 * M_PI);
	else if (dir == 'S')
		return (M_PI / 2);
	else if (dir == 'W')
		return (M_PI);
	else if (dir == 'E')
		return (0);
	return (0);
}

void	getrotationangle(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_map[i] != 0)
	{
		j = 0;
		while (g_map[i][j] != '\0')
		{
			if (g_map[i][j] == 'N' || g_map[i][j] == 'S' ||
				g_map[i][j] == 'W' || g_map[i][j] == 'E')
			{
				g_rotationangle = matchangle(g_map[i][j]);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	setup(int argc)
{
	int	bpp;
	int	size_line;
	int	endian;

	typecastmap();
	getwindowsize();
	getfirstposition();
	getrotationangle();
	g_mlx_ptr = mlx_init();
	if (argc == 2)
		g_win_ptr =
		mlx_new_window(g_mlx_ptr, g_window_width, g_window_height, "Cub3d_GNA");
	g_image_ptr =
	mlx_new_image(g_mlx_ptr, g_window_width, g_window_height);
	g_image_data =
	(int *)mlx_get_data_addr(g_image_ptr, &bpp, &size_line, &endian);
	g_rayinfo = setstructure();
	g_sprtinfo = setsprite();
	g_cpmap = setcpymap();
	g_emptmap = setemptymap(0);
}
