/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event_dinterp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:34:26 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 15:50:50 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
** Reset Camera RLocation / Rotation
*/

static void	evnt_reset_cam_rlocation_next(t_fvector new,
t_reset *s, size_t *count)
{
	if (
		nearly_equal(&get_fdf(0)->camera.r_location.x,
			new.x - 0.05f, new.x + 0.05f, new.x)
		&& nearly_equal(&get_fdf(0)->camera.r_location.y,
			new.y - 0.05f, new.y + 0.05f, new.y)
		&& nearly_equal(&get_fdf(0)->camera.r_location.z,
			new.z - 0.05f, new.z + 0.05f, new.z))
		evnt_reset_cam_rlocation(1, new);
	else
	{
		get_fdf(0)->camera.r_location.x = ft_dinterp((t_dinterp){s->nvx,
			new.x, 0.0f, 30, (*count)});
		get_fdf(0)->camera.r_location.y = ft_dinterp((t_dinterp){s->nvy,
			new.y, 0.0f, 30, (*count)});
		get_fdf(0)->camera.r_location.z = ft_dinterp((t_dinterp){s->nvz,
			new.z, 0.0f, 30, (*count)});
		++(*count);
	}
}

int	evnt_reset_cam_rlocation(int reset, t_fvector new)
{
	static t_reset		s = (t_reset){0, 0.0f, 0.0f, 0.0f};
	static size_t		count = 0;
	static int			initvalues = 1;

	if (reset)
	{
		count = 0;
		initvalues = 1;
		get_fdf(0)->event.reset_cam_rlocation = 0;
		return (1);
	}
	if (initvalues)
	{
		s.nvx = get_fdf(0)->camera.r_location.x;
		s.nvy = get_fdf(0)->camera.r_location.y;
		s.nvz = get_fdf(0)->camera.r_location.z;
		initvalues = 0;
	}
	evnt_reset_cam_rlocation_next(new, &s, &count);
	return (0);
}

/*
** Reset Camera Location
*/

static int	evnt_reset_cam_location_next(t_fvector new,
t_reset *s, size_t *count)
{
	if (
		nearly_equal(&get_fdf(0)->camera.location.x,
			new.x - 0.05f, new.x + 0.05f, new.x)
		&& nearly_equal(&get_fdf(0)->camera.location.y,
			new.y - 0.05f, new.y + 0.05f, new.y)
		&& nearly_equal(&get_fdf(0)->camera.location.z,
			new.z - 0.05f, new.z + 0.05f, new.z))
		evnt_reset_cam_location(1, new);
	else
	{
		get_fdf(0)->camera.location.x = ft_dinterp((t_dinterp){s->nvx,
			new.x, 0.0f, 10, *count});
		get_fdf(0)->camera.location.y = ft_dinterp((t_dinterp){s->nvy,
			new.y, 0.0f, 10, *count});
		get_fdf(0)->camera.location.z = ft_dinterp((t_dinterp){s->nvz,
			new.z, 0.0f, 10, *count});
		++(*count);
	}
	return (0);
}

int	evnt_reset_cam_location(int reset, t_fvector new)
{
	static t_reset		s = (t_reset){0, 0.0f, 0.0f, 0.0f};
	static size_t		count = 0;
	static int			initvalues = 1;

	if (reset)
	{
		count = 0;
		initvalues = 1;
		get_fdf(0)->event.reset_cam_location = 0;
		return (1);
	}
	if (initvalues)
	{
		s.nvx = get_fdf(0)->camera.location.x;
		s.nvy = get_fdf(0)->camera.location.y;
		s.nvz = get_fdf(0)->camera.location.z;
		initvalues = 0;
	}
	return (evnt_reset_cam_location_next(new, &s, &count));
}

/*
**	Reset height
*/

int	evnt_reset_height(int reset)
{
	static size_t	count = 0;
	double			nv;

	if (reset)
	{
		count = 0;
		get_fdf(0)->event.reset_height = 0;
		return (1);
	}
	nv = get_fdf(0)->draw.draw_z_scale;
	if (nearly_equal(&get_fdf(0)->draw.draw_z_scale, .0989f, .111f, .1f))
		evnt_reset_height(1);
	else
	{
		get_fdf(0)->draw.draw_z_scale = ft_dinterp((t_dinterp){nv,
			.1f, 1.0f / 60.0f, 240, count});
		++count;
	}
	return (0);
}
