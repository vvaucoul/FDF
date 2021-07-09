/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:28:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 13:55:50 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
** // https://isometric-tiles.readthedocs.io/en/latest/
*/

static t_vector	init_camera_location(void)
{
	t_vector	loc;

	loc.x = 141;
	loc.y = -555;
	loc.z = 0;
	return (loc);
}

void	init_camera(void)
{
	get_fdf(0)->camera.location.x = init_camera_location().x;
	get_fdf(0)->camera.location.y = init_camera_location().y;
	get_fdf(0)->camera.location.z = 0;
	get_fdf(0)->camera.r_location.x = 0;
	get_fdf(0)->camera.r_location.y = 0;
	get_fdf(0)->camera.r_location.z = 0;
	get_fdf(0)->camera.fov = 1000;
	get_fdf(0)->camera.angle = 0;
	get_fdf(0)->draw.draw_scale = get_scale_map();
}

t_fvector	get_init_camera_location(void)
{
	t_fvector	new_loc;

	new_loc = (t_fvector){init_camera_location().x,
		init_camera_location().y,
		init_camera_location().z,
		0};
	return (new_loc);
}
