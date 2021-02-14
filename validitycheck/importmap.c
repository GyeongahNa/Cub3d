/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   importmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 01:09:23 by gna               #+#    #+#             */
/*   Updated: 2020/08/29 08:04:18 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "validitycheck.h"

int		findfirstmapline(char **input)
{
	int	i;

	i = 0;
	while (input[i] != 0)
	{
		if (onlyallowed(input[i]) == 1)
			return (i);
		i++;
	}
	return (-1);
}

int		findfinalmapline(char **input, int firstmapline)
{
	int	i;

	if (firstmapline == -1)
		return (-1);
	i = firstmapline;
	while (onlyallowed(input[i]) == 1 && input[i] != 0)
		i++;
	return (i - 1);
}

int		getmaxwidth(char **input, int firstmap, int finalmap)
{
	int	maxwidth;
	int	i;

	i = firstmap;
	maxwidth = getlen(input[firstmap]);
	while (i <= finalmap)
	{
		if (maxwidth < getlen(input[i]))
			maxwidth = getlen(input[i]);
		i++;
	}
	return (maxwidth);
}

char	**setmap(int height, int width)
{
	char	**temp;
	int		i;

	temp = (char **)malloc(sizeof(char *) * (height + 1));
	i = 0;
	while (i < height)
	{
		temp[i] = (char *)malloc(sizeof(char) * (width + 1));
		i++;
	}
	temp[height] = 0;
	return (temp);
}

char	**getmap(char **input, int firstmap, int finalmap, int i)
{
	char	**temp;
	int		width;
	int		height;
	int		j;

	width = getmaxwidth(input, firstmap, finalmap);
	height = finalmap - firstmap + 1;
	temp = setmap(height, width);
	i = firstmap;
	while (i <= finalmap)
	{
		j = 0;
		while (input[i][j] != '\0')
		{
			if (input[i][j] == ' ')
				input[i][j] = 'B';
			temp[i - firstmap][j] = input[i][j];
			j++;
		}
		while (j < width)
			temp[i - firstmap][j++] = 'B';
		temp[i - firstmap][j] = '\0';
		i++;
	}
	return (temp);
}
