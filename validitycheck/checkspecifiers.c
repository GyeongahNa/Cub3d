/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkspecifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 00:03:57 by gna               #+#    #+#             */
/*   Updated: 2020/08/29 12:16:24 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validitycheck.h"

int	isrformat(char *s)
{
	int	i;

	if (s[0] != 'R')
		return (-1);
	i = 1;
	while (s[i] == ' ' && s[i] != '\0')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (-1);
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
		i++;
	if (s[i] != ' ')
		return (-1);
	while (s[i] == ' ' && s[i] != '\0')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (-1);
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
		i++;
	if (s[i] != '\0')
		return (-1);
	return (1);
}

int	isdirformat(char *s, char first, char second)
{
	int	i;

	if (s[0] != first || s[1] != second)
		return (-1);
	i = 2;
	while (s[i] == ' ' && s[i] != '\0')
		i++;
	if (s[i] < 32 || s[i] > 126)
		return (-1);
	while (s[i] >= 32 && s[i] <= 126 && s[i] != '\0')
		i++;
	if (s[i] != '\0')
		return (-1);
	return (1);
}

int	isfcformat(char *s, char fc, int i)
{
	if (s[0] != fc)
		return (-1);
	while (s[i] == ' ' && s[i] != '\0')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (-1);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i++] != ',')
		return (-1);
	while (s[i] == ' ')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (-1);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i++] != ',')
		return (-1);
	while (s[i] == ' ')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (-1);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (s[i] != '\0' ? -1 : 1);
}

int	issformat(char *s)
{
	int	i;

	if (s[0] != 'S')
		return (-1);
	i = 1;
	while (s[i] == ' ')
		i++;
	if (s[i] < 32 || s[i] > 126)
		return (-1);
	while (s[i] >= 32 && s[i] <= 126)
		i++;
	return (s[i] != '\0' ? -1 : 1);
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
