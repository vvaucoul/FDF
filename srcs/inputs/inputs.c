/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:07:07 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 21:30:40 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	input_fdf_pressed_next(int key, void *param)
{
	if (key == KEY_USER_INTERFACE)
		get_fdf(0)->draw_ui
		= *(int *)ft_ternary((int []){0}, (int []){1}, get_fdf(0)->draw_ui);
	else if (key == KEY_RESET_VIEW)
	{
		get_fdf(0)->event.reset_cam_location = 1;
		get_fdf(0)->event.reset_cam_rlocation = 1;
		get_fdf(0)->event.reset_view = 1;
		get_fdf(0)->event.reset_height = 1;
	}
	else if (key == KEY_QUIT)
		input_quit(KEY_QUIT, param);
	else if (key == KEY_SWITCH_ROTATION)
		get_fdf(0)->rotate_z
		= *(int *)ft_ternary((int []){0}, (int []){1}, get_fdf(0)->rotate_z);
	else if (key == KEY_FORCE_COLOR)
	{
		get_fdf(0)->force_color
		= *(int *)ft_ternary((int []){0}, (int []){1}, get_fdf(0)->force_color);
		fdf_force_color();
	}
	return (0);
}

int	input_fdf_pressed(int key, void *param)
{
	if (key == KEY_INCREASE_Z)
	{
		get_fdf(0)->draw.draw_z_scale += .05f;
		clamp_double(&get_fdf(0)->draw.draw_z_scale, -2, 2);
	}
	else if (key == KEY_DECREASE_Z)
	{
		get_fdf(0)->draw.draw_z_scale -= .05f;
		clamp_double(&get_fdf(0)->draw.draw_z_scale, -2, 2);
	}
	else
		input_fdf_pressed_next(key, param);
	inputs_camera(key);
	fdf_draw();
	return (0);
}

int	input_fdf_released(int key, void *param)
{
	(void)key;
	(void)param;
	return (0);
}

int	input_quit(int key, void *param)
{
	(void)key;
	(void)param;
	free_fdf();
	exit(EXIT_SUCCESS);
}

/*
**	printf("Release Key : %d\n", key);
**	printf("Press Key : %d\n", key);
*/
