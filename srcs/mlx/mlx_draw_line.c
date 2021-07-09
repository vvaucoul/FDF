/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 23:49:29 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 16:06:01 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	init_values(t_vector *delta, t_vector *sign,
t_vector start, t_vector end)
{
	delta->x = abs(end.x - start.x);
	delta->y = abs(end.y - start.y);
	sign->x = *(int *)ft_ternary((int []){1}, (int []){-1}, start.x < end.x);
	sign->y = *(int *)ft_ternary((int []){1}, (int []){-1}, start.y < end.y);
	return (0);
}

int	mlx_draw_line(t_vector start, t_vector end)
{
	t_vector	delta;
	t_vector	sign;
	t_vector	cur;
	int			error[2];

	init_values(&delta, &sign, start, end);
	error[0] = delta.x - delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		cur.color = fdf_color(cur, start, end, delta);
		mlx_draw_pixel(cur.x, cur.y, cur.color);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
	return (0);
}
