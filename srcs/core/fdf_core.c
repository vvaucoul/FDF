/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:41:55 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 21:29:52 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
** // MLX
** // CAMERA
** // MAP
** // SIZE_MAP
** // DRAW
** // EVENT
** // DRAW_UI
** // ROTATION Z
** // FORCE COLOR
*/

static t_fdf	init_fdf(void)
{
	t_fdf	fdf;

	fdf = (t_fdf){(t_mlx){NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0},
		(t_camera){(t_fvector){0.0f, 0.0f, 0.0f, 0},
		(t_fvector){0.0f, 0.0f, 0.0f, 0}, 0.0f, 0.0f},
		NULL,
		(t_vector){0, 0, 0, 0},
		(t_draw){50.0f, 0.1f},
		(t_event){0, 0, 0, 0},
		(1),
		(0),
		(0)
	};
	return (fdf);
}

t_fdf	*get_fdf(int init)
{
	static t_fdf	fdf;

	if (init)
		fdf = init_fdf();
	return (&fdf);
}

void	free_fdf(void)
{
	size_t	i;

	i = 0;
	while (i <= (size_t)get_fdf(0)->size_map.y + 1)
	{
		free(get_fdf(0)->map[i]);
		++i;
	}
	free(get_fdf(0)->map);
	mlx_clear_window(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window);
	if (get_fdf(0)->mlx.window)
		mlx_destroy_window(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window);
	if (get_fdf(0)->mlx.mlx)
	{
		mlx_destroy_display(get_fdf(0)->mlx.mlx);
		free(get_fdf(0)->mlx.mlx);
	}
}
