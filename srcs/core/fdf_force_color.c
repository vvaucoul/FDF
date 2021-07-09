/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_force_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:04:08 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 15:34:24 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	get_color_by_level(float levelscale)
{
	if (levelscale < 0.0f)
		return (FDF_COLOR_LS_00);
	else if (levelscale < 10.0f)
		return (FDF_COLOR_LS_01);
	else if (levelscale < 20.0f)
		return (FDF_COLOR_LS_02);
	return (FDF_COLOR_LS_03);
}

void	fdf_force_color(void)
{
	size_t	x;
	size_t	y;
	size_t	mx;
	size_t	my;

	x = 0;
	y = 0;
	mx = get_fdf(0)->size_map.x;
	my = get_fdf(0)->size_map.y;
	while (y <= my)
	{
		while (x <= mx)
		{
			if (!get_fdf(0)->force_color)
				get_fdf(0)->map[y][x].color
				= fdf_default_color(get_fdf(0)->map[y][x].z);
			else
				get_fdf(0)->map[y][x].color
				= get_color_by_level(get_fdf(0)->map[y][x].z);
			++x;
		}
		x = 0;
		++y;
	}
}
