/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 08:49:02 by gna               #+#    #+#             */
/*   Updated: 2020/09/05 21:40:10 by gna              ###   ########.fr       */
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

void	freestructure(void)
{
	int	i;

	i = 0;
	while (i < g_num_rays)
	{
		free(g_rayinfo[i]);
		i++;
	}
	free(g_rayinfo);
}

void	freesprtinfo(int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		free(g_sprtinfo[i]);
		i++;
	}
	free(g_sprtinfo);
}

void	freetexture(void)
{
	int	i;

	i = 0;
	while (g_texture[i] != 0)
	{
		free(g_texture[i]);
		i++;
	}
	free(g_texture);
}

void	freeintmap(int **tmap)
{
	int	i;

	i = 0;
	while (i < g_map_num_rows)
	{
		free(tmap[i]);
		i++;
	}
	free(tmap);
}

void	freeall(void)
{
	freemap(g_map);
	free(g_no_path);
	free(g_so_path);
	free(g_ea_path);
	free(g_we_path);
	free(g_s1_path);
	free(g_s2_path);
	freetexture();
	freestructure();
	freeintmap(g_imap);
	freesprtinfo(g_cnt);
	freeintmap(g_cpmap);
	freeintmap(g_emptmap);
}
