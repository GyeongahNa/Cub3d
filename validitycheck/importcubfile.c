/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   importcubfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 00:40:23 by gna               #+#    #+#             */
/*   Updated: 2020/08/29 08:20:36 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>

int		cntlines(char *path)
{
	int		fd;
	int		num;
	char	*line;
	int		cnt;

	fd = open(path, O_RDONLY);
	num = get_next_line(fd, &line);
	free(line);
	cnt = 0;
	while (num > 0)
	{
		cnt++;
		num = get_next_line(fd, &line);
		free(line);
	}
	return (cnt);
}

char	**set_input(char *path)
{
	char	**buf;
	int		fd;
	int		cnt;
	char	*line;
	int		i;

	buf = (char **)malloc(sizeof(char *) * (cntlines(path) + 1));
	fd = open(path, O_RDONLY);
	cnt = get_next_line(fd, &line);
	i = 0;
	while (cnt > 0)
	{
		buf[i] = line;
		cnt = get_next_line(fd, &line);
		i++;
	}
	buf[i] = 0;
	free(line);
	return (buf);
}
