/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validitycheck2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 00:37:37 by gna               #+#    #+#             */
/*   Updated: 2020/09/04 00:37:44 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validitycheck.h"

int	validitycheck(char *cubfile)
{
	char	**input;
	int	firstmap;
	int	finalmap;

	input = set_input(cubfile);
	if (checkinfos(input, 0) == -1)
	{
		writesentence("Error\n");
		return (-1);
	}
	firstmap = findfirstmapline(input);
	finalmap = findfinalmapline(input, firstmap);
	if (mapvalidationcheck(input, firstmap, finalmap) == -1)
	{
		writesentence("Error\n");
		return (-1);
	}
	return (1);
}
