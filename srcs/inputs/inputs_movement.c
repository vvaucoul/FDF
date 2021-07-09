/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:27:19 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 15:35:02 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	inputs_camera_rotation(int key)
{
	if (key == KEY_MOVEMENT_ROTATION_LEFT)
	{
		if (get_fdf(0)->rotate_z)
			get_fdf(0)->camera.r_location.z += CAMERA_ROTATION_ANGLE;
		else
			get_fdf(0)->camera.r_location.y -= CAMERA_ROTATION_ANGLE;
	}
	else if (key == KEY_MOVEMENT_ROTATION_RIGHT)
	{
		if (get_fdf(0)->rotate_z)
			get_fdf(0)->camera.r_location.z -= CAMERA_ROTATION_ANGLE;
		else
			get_fdf(0)->camera.r_location.y += CAMERA_ROTATION_ANGLE;
	}
	else if (key == KEY_MOVEMENT_ROTATION_UP)
	{
		get_fdf(0)->camera.r_location.x -= CAMERA_ROTATION_ANGLE;
	}
	else if (key == KEY_MOVEMENT_ROTATION_DOWN)
	{
		get_fdf(0)->camera.r_location.x += CAMERA_ROTATION_ANGLE;
	}
}

static void	inputs_camera_movement(int key)
{
	if (key == KEY_MOVEMENT_FORWARD)
	{
		get_fdf(0)->camera.location.x -= CAMERA_MOVEMENT_SPEED;
		get_fdf(0)->camera.location.y -= CAMERA_MOVEMENT_SPEED;
	}
	else if (key == KEY_MOVEMENT_BACKWARD)
	{
		get_fdf(0)->camera.location.x += CAMERA_MOVEMENT_SPEED;
		get_fdf(0)->camera.location.y += CAMERA_MOVEMENT_SPEED;
	}
	if (key == KEY_MOVEMENT_RIGHT)
	{
		get_fdf(0)->camera.location.x += CAMERA_MOVEMENT_SPEED;
		get_fdf(0)->camera.location.y -= CAMERA_MOVEMENT_SPEED;
	}
	else if (key == KEY_MOVEMENT_LEFT)
	{
		get_fdf(0)->camera.location.x -= CAMERA_MOVEMENT_SPEED;
		get_fdf(0)->camera.location.y += CAMERA_MOVEMENT_SPEED;
	}
}

static void	inputs_camera_fov(int key)
{
	if (key == KEY_INCREASE_FOV)
	{
		get_fdf(0)->draw.draw_scale++;
		clamp_double(&get_fdf(0)->draw.draw_scale, SCALE_MIN, SCALE_MAX);
	}
	else if (key == KEY_DECREASE_FOV)
	{
		get_fdf(0)->draw.draw_scale--;
		clamp_double(&get_fdf(0)->draw.draw_scale, SCALE_MIN, SCALE_MAX);
	}
}

void	inputs_camera(int key)
{
	inputs_camera_rotation(key);
	inputs_camera_movement(key);
	inputs_camera_fov(key);
}
