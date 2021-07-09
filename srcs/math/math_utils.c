/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:15:58 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 15:49:46 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	clamp_int(int *val, int min, int max)
{
	if (*val > max)
		*val = max;
	else if (*val < min)
		*val = min;
}

void	clamp_double(double *val, double min, double max)
{
	if (*val > max)
		*val = max;
	else if (*val < min)
		*val = min;
}

/*
** If value is between min & max.
** lock = lock value to choosed value
*/

int	nearly_equal(double *val, double min, double max, double lock)
{
	if (*val >= min && *val <= max)
	{
		if (lock != 0)
		{
			*val = lock;
		}
		return (1);
	}
	return (0);
}

int	int_range_clamped(t_clamp c)
{
	int	oldRange;
	int	newRange;
	int	newValue;

	newRange = c.new_max - c.new_min;
	oldRange = c.old_max - c.old_min;
	newValue = ((c.old_value - c.old_min) * newRange / oldRange) + c.new_min;
	return (newValue);
}

int	get_scale_map(void)
{
	int	val;
	int	x;
	int	y;

	x = get_fdf(0)->size_map.x;
	y = get_fdf(0)->size_map.y;
	val = int_range_clamped((t_clamp){x, 1, 200, 50, 1});
	val += int_range_clamped((t_clamp){y, 1, 200, 50, 1});
	val /= 2;
	clamp_int(&val, SCALE_MIN, SCALE_MAX);
	return (val);
}
