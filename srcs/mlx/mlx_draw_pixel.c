/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 23:55:28 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 16:06:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	mlx_draw_pixel(int x, int y, int color)
{
	int	pixel;

	if (x >= 0 && x < RES_X && y >= 0 && y < RES_Y)
	{
		pixel = (x * get_fdf(0)->mlx.bits_per_pixel / 8)
			+ (y * get_fdf(0)->mlx.size_line);
		get_fdf(0)->mlx.data_addr[pixel] = color;
		get_fdf(0)->mlx.data_addr[++pixel] = color >> 8;
		get_fdf(0)->mlx.data_addr[++pixel] = color >> 16;
	}
}
