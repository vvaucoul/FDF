/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_isometric.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:19:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 15:38:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	projection_isometric(t_vector *p)
{
	int	prev_x;
	int	prev_y;

	prev_x = (*p).x;
	prev_y = (*p).y;
	(*p).x = (prev_x - prev_y) * cos(ISOMETRIC_ANGLE);
	(*p).y = -(*p).z + (prev_x + prev_y) * sin(ISOMETRIC_ANGLE);
}

t_fvector	projection_isometric_float(t_fvector p)
{
	double	prev_x;
	double	prev_y;

	prev_x = (p).x;
	prev_y = (p).y;
	(p).x = (prev_x - prev_y) * cos(ISOMETRIC_ANGLE);
	(p).y = -(p).z + (prev_x + prev_y) * sin(ISOMETRIC_ANGLE);
	return ((t_fvector){p.x, p.y, p.z, 0});
}
