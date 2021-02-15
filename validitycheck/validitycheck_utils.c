/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validitycheck_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 01:31:53 by gna               #+#    #+#             */
/*   Updated: 2020/08/29 12:18:55 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "validitycheck.h"

int	getlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	writesentence(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], sizeof(s[i]));
		i++;
	}
}

int	endwithcub(char *s)
{
	if (getlen(s) < 4)
		return (-1);
	if (s[getlen(s) - 1] != 'b')
		return (-1);
	if (s[getlen(s) - 2] != 'u')
		return (-1);
	if (s[getlen(s) - 3] != 'c')
		return (-1);
	if (s[getlen(s) - 4] != '.')
		return (-1);
	return (1);
}

int	onlyallowed(char *s)
{
	int	i;

	if (s == 0)
		return (-1);
	if (getlen(s) == 0)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' &&
		s[i] != 'W' && s[i] != 'E' && s[i] != 'S' && s[i] != 'N')
			return (-1);
		i++;
	}
	return (1);
}
