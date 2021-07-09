/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:59:44 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 13:59:05 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return (*(double *)ft_ternary((double []){1.0},
		(double []){placement / distance}, distance == 0));
}

static int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	fdf_color(t_vector current, t_vector start, t_vector end, t_vector delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	fdf_default_color(int z)
{
	double	percentage;

	percentage = percent(MAP_Z_MIN, MAP_Z_MAX, z);
	if (percentage < 0.2)
		return (mlx_color(129, 219, 55));
	else if (percentage < 0.4)
		return (mlx_color(92, 50, 37));
	else if (percentage < 0.6)
		return (mlx_color(58, 67, 194));
	else if (percentage < 0.8)
		return (mlx_color(92, 50, 37));
	else
		return (mlx_color(201, 202, 212));
}
