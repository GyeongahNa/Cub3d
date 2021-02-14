/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkspecifiers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:57:27 by gna               #+#    #+#             */
/*   Updated: 2020/09/05 22:33:51 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validitycheck_bonus.h"

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

int	checkdirinfos(char **input)
{
	int	i;
	int	isno;
	int	isso;
	int	iswe;
	int	isea;

	isno = 0;
	isso = 0;
	iswe = 0;
	isea = 0;
	i = 0;
	while (input[i] != 0)
	{
		if (isdirformat(input[i], 'N', 'O') == 1)
			isno = 1;
		else if (isdirformat(input[i], 'E', 'A') == 1)
			isea = 1;
		else if (isdirformat(input[i], 'W', 'E') == 1)
			iswe = 1;
		else if (isdirformat(input[i], 'S', 'O') == 1)
			isso = 1;
		i++;
	}
	return ((isno != 1 || isso != 1 || iswe != 1 || isea != 1) ? -1 : 1);
}

int	checkinfos(char **input, int i, int iss1, int iss2)
{
	int	isr;

	if (checkdirinfos(input) == -1 || checkfcinfos(input) == -1)
	{
		freeinput(input);
		return (-1);
	}
	isr = 0;
	while (input[i] != 0)
	{
		if (isrformat(input[i]) == 1)
			isr = 1;
		else if (iss1format(input[i]) == 1)
			iss1 = 1;
		else if (iss2format(input[i]) == 1)
			iss2 = 1;
		i++;
	}
	if (isr != 1 || iss1 != 1 || iss2 != 1)
	{
		freeinput(input);
		return (-1);
	}
	return (1);
}
