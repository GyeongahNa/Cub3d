/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 00:43:29 by gna               #+#    #+#             */
/*   Updated: 2020/09/05 09:29:06 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVINGBMP_H
# define SAVINGBMP_H

void					rendersprite(int num);
static int				extract_color(int x, int y);
static int				fill_bmp_color(int fd, int pad);
static	void			int_to_char(unsigned char *num,
int value);
static int				write_bmp_header(int fd, int file_size);

#endif
