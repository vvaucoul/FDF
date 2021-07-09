/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:35:19 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 15:32:10 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static	void	rotate_x(t_vector *p)
{
	int	prev_y;

	prev_y = p->y;
	p->y = prev_y * cos(get_fdf(0)->camera.r_location.x)
		+ p->z * sin(get_fdf(0)->camera.r_location.x);
	p->z = -prev_y * sin(get_fdf(0)->camera.r_location.x)
		+ p->z * cos(get_fdf(0)->camera.r_location.x);
}

static	void	rotate_y(t_vector *p)
{
	int	prev_x;

	prev_x = p->x;
	p->x = prev_x * cos(get_fdf(0)->camera.r_location.y)
		+ p->z * sin(get_fdf(0)->camera.r_location.y);
	p->z = -prev_x * sin(get_fdf(0)->camera.r_location.y)
		+ p->z * cos(get_fdf(0)->camera.r_location.y);
}

static	void	rotate_z(t_vector *p)
{
	int	prev_x;
	int	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	p->x = prev_x * cos(get_fdf(0)->camera.r_location.z)
		- prev_y * sin(get_fdf(0)->camera.r_location.z);
	p->y = prev_x * sin(get_fdf(0)->camera.r_location.z)
		+ prev_y * cos(get_fdf(0)->camera.r_location.z);
}

void	rotate_xyz(t_vector *p)
{
	p->x -= (get_fdf(0)->size_map.x * get_fdf(0)->draw.draw_scale) / 2;
	p->y -= (get_fdf(0)->size_map.y * get_fdf(0)->draw.draw_scale) / 2;
	rotate_x(p);
	rotate_y(p);
	rotate_z(p);
	p->x += (RES_X / 2) + get_fdf(0)->camera.location.x;
	p->y += (RES_Y + get_fdf(0)->size_map.y
			* get_fdf(0)->draw.draw_scale) / 2 + get_fdf(0)->camera.location.y;
}
