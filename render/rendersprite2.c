/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendersprite2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 00:23:43 by gna               #+#    #+#             */
/*   Updated: 2020/09/04 00:24:08 by gna              ###   ########.fr       */
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

void	rendersprite(int num)
{
	int		colstart;
	int		colend;
	double	wallheight;

	if (num <= 0)
		return ;
	num--;
	cpyemptymap();
	while (num >= 0)
	{
		wallheight = g_sprtinfo[num]->wallheight;
		colstart = getcenter(num) - 0.5 * wallheight;
		colend = getcenter(num) + 0.5 * wallheight;
		renderwidth(colstart, colend, num);
		g_emptmap[g_sprtinfo[num]->map_y][g_sprtinfo[num]->map_x] = 2;
		raycast(g_emptmap, 0, 3);
		renderfrontwall();
		num--;
	}
}
