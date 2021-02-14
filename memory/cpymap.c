/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 10:01:34 by gna               #+#    #+#             */
/*   Updated: 2020/09/05 10:05:39 by gna              ###   ########.fr       */
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

void			cpymap(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_map_num_rows)
	{
		j = 0;
		while (j < g_map_num_cols)
		{
			g_cpmap[i][j] = g_imap[i][j];
			j++;
		}
		g_cpmap[i][j] = '\0';
		i++;
	}
}

void			cpyemptymap(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_map_num_rows)
	{
		j = 0;
		while (j < g_map_num_cols)
		{
			g_emptmap[i][j] = g_imap[i][j];
			if (g_imap[i][j] != 1)
				g_emptmap[i][j] = 0;
			j++;
		}
		g_emptmap[i][j] = '\0';
		i++;
	}
}
