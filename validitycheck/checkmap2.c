/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:46:44 by gna               #+#    #+#             */
/*   Updated: 2020/08/29 12:07:57 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validitycheck.h"

char	**g_map = 0;

int	checkmap(char **temp, int width, int height)
{
	if (checkmapcontent(temp, width, height) == -1 ||
		checkaroundb(temp, width, height) == -1 ||
		checkedge(temp, width, height) == -1)
		return (-1);
	return (1);
}

int	mapvalidationcheck(char **input, int firstmap, int finalmap)
{
	int		numrows;
	int		height;
	char	**temp;
	int		width;

	if (firstmap == -1)
		return (-1);
	numrows = 0;
	while (input[numrows] != 0)
		numrows++;
	if (finalmap != numrows - 1)
		return (-1);
	width = getmaxwidth(input, firstmap, finalmap);
	height = finalmap - firstmap + 1;
	temp = getmap(input, firstmap, finalmap, 0);
	if (checkmap(temp, width, height) == -1)
	{
		freemap(temp);
		freeinput(input);
		return (-1);
	}
	g_map = temp;
	collectinfos(input, 0);
	freeinput(input);
	return (1);
}
