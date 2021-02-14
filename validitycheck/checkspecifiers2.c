/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkspecifiers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:57:27 by gna               #+#    #+#             */
/*   Updated: 2020/08/29 12:16:47 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validitycheck.h"

int	checkfcinfos(char **input)
{
	int	i;
	int	isf;
	int	isc;

	isc = 0;
	isf = 0;
	i = 0;
	while (input[i] != 0)
	{
		if (isfcformat(input[i], 'F', 1) == 1)
			isf = 1;
		else if (isfcformat(input[i], 'C', 1) == 1)
			isc = 1;
		i++;
	}
	if (isc != 1 || isf != 1)
		return (-1);
	return (1);
}

int	checkinfos(char **input, int i)
{
	int	isr;
	int	iss;

	if (checkdirinfos(input) == -1 || checkfcinfos(input) == -1)
	{
		freeinput(input);
		return (-1);
	}
	isr = 0;
	iss = 0;
	while (input[i] != 0)
	{
		if (isrformat(input[i]) == 1)
			isr = 1;
		else if (issformat(input[i]) == 1)
			iss = 1;
		i++;
	}
	if (isr != 1 || iss != 1)
	{
		freeinput(input);
		return (-1);
	}
	return (1);
}
