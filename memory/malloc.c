/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:15:32 by gna               #+#    #+#             */
/*   Updated: 2020/09/06 00:11:52 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "../validitycheck/validitycheck.h"
#include "../header/mlx.h"
#include "../header/keyinfo.h"
#include "../header/raycast.h"

t_rayinfo	**setstructure(void)
{
	t_rayinfo	**rayinfo;
	int		i;

	rayinfo =\
	(struct s_rayinfo **)malloc(sizeof(struct s_rayinfo *) * g_num_rays);
	i = 0;
	while (i < g_num_rays)
	{
		rayinfo[i] = (struct s_rayinfo *)malloc(sizeof(struct s_rayinfo));
		i++;
	}
	return (rayinfo);
}

t_spriteinfo	**setsprite(void)
{
	t_spriteinfo	**sprtinfo;
	int				i;

	sprtinfo =\
	(struct s_spriteinfo**)malloc(sizeof(struct s_spriteinfo *) * g_num_rays);
	i = 0;
	while (i < g_num_rays)
	{
		sprtinfo[i] =\
		(struct s_spriteinfo *)malloc(sizeof(struct s_spriteinfo));
		i++;
	}
	return (sprtinfo);
}

int	**setcpymap(void)
{
	int	**cpmap;
	int	i;

	cpmap = (int **)malloc(sizeof(int *) * (g_map_num_rows + 1));
	i = 0;
	while (i < g_map_num_rows)
	{
		cpmap[i] = (int *)malloc(sizeof(int) * (g_map_num_cols + 1));
		i++;
	}
	cpmap[g_map_num_rows] = 0;
	return (cpmap);
}

int	**setemptymap(int i)
{
	int	**emptmap;

	emptmap = (int **)malloc(sizeof(int *) * (g_map_num_rows + 1));
	i = 0;
	while (i < g_map_num_rows)
	{
		emptmap[i] = (int *)malloc(sizeof(int) * (g_map_num_cols + 1));
		i++;
	}
	return (emptmap);
}
