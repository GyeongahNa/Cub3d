/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 09:55:35 by gna               #+#    #+#             */
/*   Updated: 2020/09/06 00:20:27 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "validitycheck/validitycheck.h"
#include "header/keyinfo.h"
#include "header/raycast.h"
#include "header/mlx.h"

int				**g_imap = NULL;
void				*g_mlx_ptr = NULL;
void				*g_win_ptr = NULL;
void				*g_image_ptr = NULL;
int				*g_image_data = NULL;
void				*g_xpm_image_ptr = NULL;
int				*g_xpm_image_data = NULL;
int				**g_texture = NULL;
t_rayinfo		**g_rayinfo = NULL;
t_spriteinfo		**g_sprtinfo = NULL;
int				**g_cpmap = NULL;
int				**g_emptmap = NULL;
double			g_turndirection = 0;
double			g_walkdirection = 0;
double			g_lrwalkdirection = 0;
double			g_movespeed = 5;
double			g_rotationspeed = 3 * (M_PI / 180);
int				g_argc = 0;
int				g_tile_size = 60;
int				g_map_num_rows = 0;
int				g_map_num_cols = 0;
int				g_window_width = 0;
int				g_window_height = 0;
int				g_num_rays = 0;
double			g_middleline = 0;
double			g_player_x = 0;
double			g_player_y = 0;
double			g_rotationangle = 0;
double			g_life = 100;
int				g_cnt;

int				render(int argc)
{
	int cnt;

	clearimage();
	raycast(g_imap, 0, 2);
	renderfloor();
	renderceiling();
	wallrendering(0, 0, 0, 0);
	cnt = savespriteinfo();
	rendersprite(cnt);
	raycast(g_imap, 0, 3);
	rendermap();
	renderrays(0, 0, 0);
	if (argc == 3)
	{
		save_bmp();
		destroywindow();
	}
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_image_ptr, 0, 0);
	return (0);
}

int				main_loop(void)
{
	update();
	render(g_argc);
	return (0);
}

int				main(int argc, char *argv[])
{
	if (argc <= 1)
		return (noscenemessage());
	if (argc >= 4)
		return (toomuchmessage());
	if (endwithcub(argv[1]) == -1)
		return (incorrectformatmessage());
	if (argc == 3 && issave(argv[2]) != 1)
		return (nosavemessage());
	if (validitycheck(argv[1]) == -1)
		return (-1);
	g_argc = argc;
	setup(g_argc);
	load_texture();
	if (argc == 2)
		processinput();
	mlx_loop_hook(g_mlx_ptr, main_loop, (void *)(0));
	mlx_loop(g_mlx_ptr);
}
