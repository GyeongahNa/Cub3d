/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validitycheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 01:24:36 by gna               #+#    #+#             */
/*   Updated: 2020/09/04 00:38:22 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validitycheck.h"

int			noscenemessage(void)
{
	writesentence("Error : no scene discription file.\n");
	return (-1);
}

int			toomuchmessage(void)
{
	writesentence("Error : too many arguments were input.");
	return (-1);
}

int			incorrectformatmessage(void)
{
	writesentence("Error : format of scene discription file isn't '.cub'.\n");
	return (-1);
}

int			nosavemessage(void)
{
	writesentence(
	"Error : The number of arguments is two, \
	but no '--save' argument\n");
	return (-1);
}

int			issave(char *s)
{
	char	*save;
	int		i;

	save = "--save";
	i = 0;
	while (save[i] == s[i] && save[i] != '\0' && s[i] != '\0')
		i++;
	if (save[i] == '\0' && s[i] == '\0')
		return (1);
	return (-1);
}
