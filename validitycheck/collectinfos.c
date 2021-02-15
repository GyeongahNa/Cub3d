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

int	g_r_width = 0;
int	g_r_height = 0;
char	*g_so_path = 0;
char	*g_we_path = 0;
char	*g_no_path = 0;
char	*g_ea_path = 0;
char	*g_s_path = 0;
int	g_f_r = 0;
int	g_f_g = 0;
int	g_f_b = 0;
int	g_c_r = 0;
int	g_c_g = 0;
int	g_c_b = 0;

int	getwidth(char *s)
{
	int	i;
	int	j;
	char	*temp;
	int	width;

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
	width = ft_atoi(temp);
	free(temp);
	return (width);
}

int	getheight(char *s)
{
	int	i;
	int	j;
	int	height;
	char	*temp;

	i = 1;
	temp = (char *)malloc(sizeof(char) * (getlen(s) + 1));
	while (s[i] == ' ')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
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
	height = ft_atoi(temp);
	free(temp);
	return (height);
}

char	*getpath(char *s)
{
	int	i;
	int	j;
	char	*temp;

	i = 2;
	temp = (char *)malloc(sizeof(char) * getlen(s) + 1);
	while (s[i] == ' ')
		i++;
	j = 0;
	while (s[i] >= 32 && s[i] <= 126)
	{
		temp[j] = s[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*getspath(char *s)
{
	int	i;
	int	j;
	char	*temp;

	i = 1;
	temp = (char *)malloc(sizeof(char) * (getlen(s) + 1));
	while (s[i] == ' ')
		i++;
	j = 0;
	while (s[i] >= 32 && s[i] <= 126)
	{
		temp[j] = s[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
}
