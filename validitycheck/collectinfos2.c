/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectinfos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:17:37 by gna               #+#    #+#             */
/*   Updated: 2020/08/29 12:23:18 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validitycheck.h"
#include <stdlib.h>

int	getrcolor(char *s)
{
	int	i;
	int	j;
	char	*temp;
	int	r;

	i = 1;
	temp = (char *)malloc(sizeof(char) * (getlen(s) + 1));
	while (s[i] == ' ')
		i++;
	j = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		temp[j] = s[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	r = ft_atoi(temp);
	free(temp);
	return (r);
}

int	getgcolor(char *s)
{
	int	i;
	int	j;
	char	*temp;
	int	g;

	temp = (char *)malloc(sizeof(char) * (getlen(s) + 1));
	i = 1;
	while (s[i] != ' ')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	i++;
	while (s[i] == ' ')
		i++;
	j = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		temp[j] = s[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	g = ft_atoi(temp);
	free(temp);
	return (g);
}

int	getbcolor(char *s, int i, int j, char *temp)
{
	temp = (char *)malloc(sizeof(char) * (getlen(s) + 1));
	while (s[i] == ' ')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	i++;
	while (s[i] == ' ')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	i++;
	while (s[i] == ' ')
		i++;
	j = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		temp[j] = s[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	j = ft_atoi(temp);
	free(temp);
	return (j);
}

void	getrgb(char *s, int fc)
{
	if (fc == 'F')
	{
		g_f_r = getrcolor(s);
		g_f_g = getgcolor(s);
		g_f_b = getbcolor(s, 1, 0, 0);
	}
	else if (fc == 'C')
	{
		g_c_r = getrcolor(s);
		g_c_g = getgcolor(s);
		g_c_b = getbcolor(s, 1, 0, 0);
	}
}

void	collectinfos(char **input, int i)
{
	i = 0;
	while (input[i] != 0)
	{
		if (isrformat(input[i]) == 1)
		{
			g_r_width = getwidth(input[i]);
			g_r_height = getheight(input[i]);
		}
		else if (isdirformat(input[i], 'N', 'O') == 1)
			g_no_path = getpath(input[i]);
		else if (isdirformat(input[i], 'S', 'O') == 1)
			g_so_path = getpath(input[i]);
		else if (isdirformat(input[i], 'W', 'E') == 1)
			g_we_path = getpath(input[i]);
		else if (isdirformat(input[i], 'E', 'A') == 1)
			g_ea_path = getpath(input[i]);
		else if (issformat(input[i]) == 1)
			g_s_path = getspath(input[i]);
		else if (isfcformat(input[i], 'F', 1) == 1)
			getrgb(input[i], 'F');
		else if (isfcformat(input[i], 'C', 1) == 1)
			getrgb(input[i], 'C');
		i++;
	}
}
