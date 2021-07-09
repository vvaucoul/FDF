/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:25:04 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 16:35:30 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	bresenham(t_vector s, t_vector e)
{
	int	err;

	err = (int)fabs((double)e.x - s.x) - (int)fabs((double)e.y - s.y);
	while (1)
	{
		mlx_draw_pixel((int)round(s.x), (int)round(s.y), s.color);
		if (2 * err >= -(int)fabs((double)e.y - s.y))
		{
			if ((int)round(s.x) == (int)round(e.x))
				break ;
			err += -(int)fabs((double)e.y - s.y);
			s.x = *(int *)ft_ternary((int []){1}, (int []){-1}, s.x < e.x);
		}
		if (2 * err <= (int)fabs((double)(e.x - s.x)))
		{
			if ((int)round(s.y) == (int)round(e.y))
				break ;
			err += (int)fabs((double)(e.x - s.x));
			s.y = *(int *)ft_ternary((int []){1}, (int []){-1}, s.y < e.y);
		}
	}
}
