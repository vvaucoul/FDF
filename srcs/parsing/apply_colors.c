/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:00:50 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 16:39:05 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static	int	has_already_color(void)
{
	t_vector	v;

	v = (t_vector){0, 0, 0, 0};
	while (v.y < get_fdf(0)->size_map.y)
	{
		while (v.x < get_fdf(0)->size_map.x)
		{
			if (get_fdf(0)->map[v.y][v.x].color != COLOR_WHITE)
				return (1);
			++v.x;
		}
		v.x = 0;
		++v.y;
	}
	return (0);
}

static	int	get_color(t_fvector pos)
{
	return (fdf_default_color(pos.z));
}

int	apply_colors(void)
{
	t_vector	v;

	if (has_already_color())
		return (0);
	v = (t_vector){0, 0, 0, 0};
	while (v.y <= get_fdf(0)->size_map.y)
	{
		while (v.x <= get_fdf(0)->size_map.x)
		{
			get_fdf(0)->map[v.y][v.x].color = get_color((t_fvector){
				get_fdf(0)->map[v.y][v.x].x,
				get_fdf(0)->map[v.y][v.x].y,
				get_fdf(0)->map[v.y][v.x].z,
				0
			});
			++v.x;
		}
		v.x = 0;
		++v.y;
	}
	return (0);
}
