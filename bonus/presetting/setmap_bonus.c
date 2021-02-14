/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:51:37 by gna               #+#    #+#             */
/*   Updated: 2020/09/05 21:38:57 by gna              ###   ########.fr       */
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

int		getmapwidth(void)
{
	int	width;

	width = 0;
	while (g_map[0][width] != '\0')
		width++;
	return (width);
}

int		getmapheight(void)
{
	int	height;

	height = 0;
	while (g_map[height] != 0)
		height++;
	return (height);
}

void	typecastmap(void)
{
	int	i;
	int	j;

	g_imap = (int **)malloc(sizeof(int *) * (getmapheight() + 1));
	i = 0;
	while (i < getmapheight())
		g_imap[i++] = (int *)malloc(sizeof(int) * (getmapwidth()));
	g_imap[getmapheight()] = 0;
	i = 0;
	while (i < getmapheight())
	{
		j = 0;
		while (j < getmapwidth())
		{
			if (g_map[i][j] != '1' && g_map[i][j] != '2'
			&& g_map[i][j] != '3')
				g_imap[i][j] = 0;
			else
				g_imap[i][j] = g_map[i][j] - '0';
			j++;
		}
		i++;
	}
}
