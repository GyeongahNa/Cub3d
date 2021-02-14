/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroywindow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 08:46:33 by gna               #+#    #+#             */
/*   Updated: 2020/09/03 08:46:39 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "../validitycheck/validitycheck_bonus.h"
#include "../header/mlx_bonus.h"
#include "../header/keyinfo_bonus.h"
#include "../header/raycast_bonus.h"

int	destroywindow(void)
{
	freeall();
	mlx_destroy_image(g_mlx_ptr, g_image_ptr);
	if (g_argc == 2)
	{
		mlx_clear_window(g_mlx_ptr, g_win_ptr);
		mlx_destroy_window(g_mlx_ptr, g_win_ptr);
	}
	exit(0);
	return (0);
}
