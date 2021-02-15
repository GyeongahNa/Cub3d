/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 09:47:01 by gna               #+#    #+#             */
/*   Updated: 2020/09/04 01:24:07 by gna              ###   ########.fr       */
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

int	*load_image(char *path, int s, int b, int e)
{
	int	*res;
	int	x;
	int	y;
	int	w;
	int	h;

	g_xpm_image_ptr = mlx_xpm_file_to_image(g_mlx_ptr, path, &w, &h);
	g_xpm_image_data = (int *)mlx_get_data_addr(g_xpm_image_ptr, &b, &s, &e);
	res = (int *)malloc(sizeof(int) * TEXWIDTH * TEXHEIGHT);
	y = 0;
	while (y < TEXHEIGHT)
	{
		x = 0;
		while (x < TEXWIDTH)
		{
			res[TEXWIDTH * y + x] = g_xpm_image_data[TEXWIDTH * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(g_mlx_ptr, g_xpm_image_ptr);
	return (res);
}

void	load_texture(void)
{
	g_texture = (int **)malloc(sizeof(int *) * 6);
	g_texture[0] = load_image(g_no_path, 0, 0, 0);
	g_texture[1] = load_image(g_ea_path, 0, 0, 0);
	g_texture[2] = load_image(g_so_path, 0, 0, 0);
	g_texture[3] = load_image(g_we_path, 0, 0, 0);
	g_texture[4] = load_image(g_s_path, 0, 0, 0);
	g_texture[5] = 0;
}
