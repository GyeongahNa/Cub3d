/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 23:48:53 by gna               #+#    #+#             */
/*   Updated: 2020/08/29 07:59:20 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#define BUFFER_SIZE 30

int			str_len(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

char		*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(str + i));
	return ((char *)(0));
}

int			to_line(int fd, char **arr, char **line)
{
	int		len;
	char	*tmp;

	len = str_len(arr[fd]);
	if (arr[fd][len] == '\n')
	{
		*line = ft_substr(arr[fd], 0, len);
		tmp = ft_strdup(arr[fd] + len + 1);
		free(arr[fd]);
		arr[fd] = NULL;
		arr[fd] = tmp;
		if (arr[fd][0] == '\0')
		{
			free(arr[fd]);
			arr[fd] = 0;
		}
		return (1);
	}
	else
	{
		*line = ft_strdup(arr[fd]);
		free(arr[fd]);
		arr[fd] = 0;
		return (0);
	}
}

int			output(int ret, int fd, char **arr, char **line)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && arr[fd] == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (to_line(fd, arr, line));
}

int			get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*arr[1024] = {0, };
	char		*tmp;
	int			ret;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (arr[fd] == 0)
			arr[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(arr[fd], buff);
			free(arr[fd]);
			arr[fd] = NULL;
			arr[fd] = tmp;
		}
		if (ft_strchr(arr[fd], '\n'))
			break ;
	}
	free(buff);
	return (output(ret, fd, arr, line));
}
