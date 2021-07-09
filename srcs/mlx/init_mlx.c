/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 22:46:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 15:57:15 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	init_mlx(void)
{
	get_fdf(0)->mlx.mlx = mlx_init();
	if (!(get_fdf(0)->mlx.mlx))
		return (return_error("Failed to load minilibx", -1));
	get_fdf(0)->mlx.window = mlx_new_window(get_fdf(0)->mlx.mlx,
		RES_X, RES_Y, WINDOW_TITLE);
	if (!(get_fdf(0)->mlx.window))
		return (return_error("Failed to create window", -1));
	return (1);
}

int	init_image(void)
{
	get_fdf(0)->mlx.img = mlx_new_image(get_fdf(0)->mlx.mlx, RES_X, RES_Y);
	if (!(get_fdf(0)->mlx.img))
		return (return_error("Failed to create image", -1));
	get_fdf(0)->mlx.data_addr = mlx_get_data_addr(get_fdf(0)->mlx.img,
		&get_fdf(0)->mlx.bits_per_pixel,
		&get_fdf(0)->mlx.size_line, &get_fdf(0)->mlx.endian);
	if (!(get_fdf(0)->mlx.data_addr))
		return (return_error("Failed to image data", -1));
	return (0);
}
