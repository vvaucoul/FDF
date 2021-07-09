/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:33:02 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 15:54:12 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	loading_reset(size_t i, char *str)
{
	size_t	ci;

	ci = 0;
	ft_putstr("\r");
	while (ci < (ft_strlen(str) + 3))
	{
		ft_putstr(" ");
		++ci;
	}
	ft_putstr(str);
	if ((i > 10))
		ft_putstr("...");
	else if ((i > 5))
		ft_putstr("..");
	else
		ft_putstr(".");
}

int	fdf_event_check_values(void)
{
	if (get_fdf(0)->event.reset_view)
		evnt_reset_view(0);
	if (get_fdf(0)->event.reset_height)
		evnt_reset_height(0);
	if (get_fdf(0)->event.reset_cam_location)
		evnt_reset_cam_location(0, get_init_camera_location());
	if (get_fdf(0)->event.reset_cam_rlocation)
		evnt_reset_cam_rlocation(0, (t_fvector){0, 0, 0, 0});
	return (0);
}

/*
** Reset View
*/

int	evnt_reset_view(int reset)
{
	static size_t	count = 0;
	double			nv;

	if (reset)
	{
		count = 0;
		get_fdf(0)->event.reset_view = 0;
		return (1);
	}
	nv = get_fdf(0)->draw.draw_scale;
	if ((nearly_equal(&get_fdf(0)->draw.draw_scale,
				(double)get_scale_map() - 0.05f,
				(double)get_scale_map() + 0.5f, (double)get_scale_map())))
		evnt_reset_view(1);
	else
	{
		get_fdf(0)->draw.draw_scale = ft_dinterp((t_dinterp){nv,
			get_scale_map(), 1.0f / 60.0f, 90, count});
		++count;
	}
	return (0);
}

/*
**	FDF EVENT
*/

int	fdf_event(void)
{
	static size_t	i = 0;

	fdf_event_check_values();
	if (get_fdf(0)->event.reset_view
		|| get_fdf(0)->event.reset_height
		|| get_fdf(0)->event.reset_cam_location
		|| get_fdf(0)->event.reset_cam_rlocation)
	{
		fdf_draw();
		loading_reset(i++, "\rLoading reset View");
		i = *(size_t *)ft_ternary((size_t []){0}, (size_t []){i}, i > 15);
	}
	else if (i != 0)
	{
		ft_putstr("\nView Reset...\n");
		i = 0;
		fdf_draw();
	}
	return (0);
}
