/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:06:43 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 21:10:10 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	mlx_draw_background(void)
{
	size_t	i;

	i = 0;
	while (i < RES_X * RES_Y * 4)
	{
		get_fdf(0)->mlx.data_addr[i] = mlx_color(17, 18, 18);
		i += 4;
	}
}
