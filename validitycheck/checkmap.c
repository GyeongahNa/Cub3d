/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:37:20 by gna               #+#    #+#             */
/*   Updated: 2020/08/28 23:37:28 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validitycheck.h"

int	iswallorb(char **tmap, int y, int x)
{
	int	width;
	int	height;

	width = 0;
	while (tmap[0][width] != '\0')
		width++;
	height = 0;
	while (tmap[height] != 0)
		height++;
	if ((y >= 0 && y <= height - 1) && (x >= 0 && x <= width - 1))
	{
		if (tmap[y][x] != '1' && tmap[y][x] != 'B')
			return (-1);
	}
	return (1);
}

int	checkaroundb(char **tmap, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (tmap[i][j] == 'B')
			{
				if (iswallorb(tmap, i - 1, j) == -1 ||
				iswallorb(tmap, i + 1, j) == -1 ||
				iswallorb(tmap, i, j - 1) == -1 ||
				iswallorb(tmap, i, j + 1) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	checkedge(char **tmap, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				if (tmap[i][j] != 'B' && tmap[i][j] != '1')
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is4char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' ||
	c == 'W' || c == '0' || c == '1' || c == '2' || c == 'B')
		return (1);
	else
		return (-1);
}

int	checkmapcontent(char **temp, int width, int height)
{
	int	i;
	int	j;
	int	isdir;

	i = 0;
	isdir = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (is4char(temp[i][j]) == -1)
				return (-1);
			if (temp[i][j] == 'N' || temp[i][j] == 'S' ||
			temp[i][j] == 'E' || temp[i][j] == 'W')
				isdir = 1;
			j++;
		}
		i++;
	}
	if (isdir == 0)
		return (-1);
	return (1);
}
