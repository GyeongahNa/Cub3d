/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderhud_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:13:26 by gna               #+#    #+#             */
/*   Updated: 2020/09/05 22:13:57 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/raycast_bonus.h"

void	renderhud(void)
{
	int	i;
	int	j;

	i = g_window_height / 2 - 17;
	while (i < g_window_height / 2 + 17)
	{
		j = g_window_width / 2;
		while (j < g_window_width / 2 + 2)
		{
			g_image_data[(int)(g_window_width * i + j)] = 255 * 256 * 256;
			j++;
		}
		i++;
	}
	j = g_window_width / 2 - 17;
	while (j < g_window_width / 2 + 17)
	{
		i = g_window_height / 2;
		while (i < g_window_height / 2 + 2)
		{
			g_image_data[(int)(j + g_window_width * i)] = 255 * 256 * 256;
			i++;
		}
		j++;
	}
}
