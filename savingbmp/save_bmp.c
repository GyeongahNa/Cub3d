/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:42:03 by gna               #+#    #+#             */
/*   Updated: 2020/09/03 14:58:55 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "../validitycheck/validitycheck.h"
#include "../header/keyinfo.h"
#include "../header/raycast.h"
#include "../header/mlx.h"

static int			extract_color(int x, int y)
{
	int	rgb;
	int	color;

	color = g_image_data[x + (g_window_height - 1 - y) * g_window_width];
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int			fill_bmp_color(int fd, int pad)
{
	unsigned char	zero[3];
	int				x;
	int				y;
	int				color;

	ft_memset(zero, 0, 3);
	y = 0;
	while (y < g_window_height)
	{
		x = 0;
		while (x < g_window_width)
		{
			color = extract_color(x, y);
			if (write(fd, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(fd, &zero, pad) < 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static	void		int_to_char(unsigned char *num, int value)
{
	num[0] = (unsigned char)(value);
	num[1] = (unsigned char)(value >> 8);
	num[2] = (unsigned char)(value >> 16);
	num[3] = (unsigned char)(value >> 24);
}

static int			write_bmp_header(int fd, int file_size)
{
	unsigned char	bmp_file_header[14];
	unsigned char	bmp_info_header[40];

	ft_memset(bmp_file_header, 0, 14);
	bmp_file_header[0] = (unsigned char)('B');
	bmp_file_header[1] = (unsigned char)('M');
	int_to_char(bmp_file_header + 2, file_size);
	bmp_file_header[10] = (unsigned char)(54);
	if (write(fd, bmp_file_header, 14) < 0)
		return (0);
	ft_memset(bmp_info_header, 0, 40);
	bmp_info_header[0] = (unsigned char)(40);
	int_to_char(bmp_info_header + 4, g_window_width);
	int_to_char(bmp_info_header + 8, g_window_height);
	bmp_info_header[12] = (unsigned char)(1);
	bmp_info_header[14] = (unsigned char)(24);
	if (write(fd, bmp_info_header, 40) < 0)
		return (0);
	return (1);
}

int					save_bmp(void)
{
	int	fd;
	int	file_size;
	int	pad;

	fd = 0;
	pad = (4 - (g_window_width * 3) % 4) % 4;
	if ((fd = open("savedimage.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644)) < 0)
		return (0);
	file_size = 54 + ((g_window_width + pad) * g_window_height);
	if (!write_bmp_header(fd, file_size))
		return (0);
	if (!fill_bmp_color(fd, pad))
		return (0);
	close(fd);
	return (0);
}
