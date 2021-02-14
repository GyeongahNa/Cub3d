/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 00:33:18 by gna               #+#    #+#             */
/*   Updated: 2020/08/29 00:33:24 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "validitycheck_bonus.h"

void	freemap(char **tmap)
{
	int	i;

	i = 0;
	while (tmap[i] != 0)
	{
		free(tmap[i]);
		i++;
	}
	free(tmap);
}

void	freeinput(char **input)
{
	int	i;

	i = 0;
	while (input[i] != 0)
	{
		free(input[i]);
		i++;
	}
	free(input);
}
