/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 00:16:02 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 14:04:59 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static t_vector	get_map_vector(int x, int y)
{
	return ((t_vector){
		get_fdf(0)->map[y][x].x * get_fdf(0)->draw.draw_scale,
		get_fdf(0)->map[y][x].y * get_fdf(0)->draw.draw_scale,
		get_fdf(0)->map[y][x].z * get_fdf(0)->draw.draw_scale
		* get_fdf(0)->draw.draw_z_scale,
		get_fdf(0)->map[y][x].color});
}

static t_vector	*get_projection(int x, int y)
{
	t_vector	*v;

	x = *(int *)ft_ternary((int []){get_fdf(0)->size_map.x},
			(int []){x}, (x > get_fdf(0)->size_map.x));
	y = *(int *)ft_ternary((int []){get_fdf(0)->size_map.y},
			(int []){y}, (y > get_fdf(0)->size_map.y));
	if (!(ft_memret((void **)&v, sizeof(t_vector), 4)))
		return (NULL);
	v[0] = get_map_vector(x, y);
	rotate_xyz(&v[0]);
	projection_isometric(&v[0]);
	v[1] = get_map_vector(x + 1, y);
	rotate_xyz(&v[1]);
	projection_isometric(&v[1]);
	v[2] = get_map_vector(x, y + 1);
	rotate_xyz(&v[2]);
	projection_isometric(&v[2]);
	v[3] = get_map_vector(x + 1, y + 1);
	rotate_xyz(&v[3]);
	projection_isometric(&v[3]);
	return (v);
}

static int	fdf_end_draw(void)
{
	mlx_put_image_to_window(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		get_fdf(0)->mlx.img, 0, 0);
	user_interface();
	mlx_destroy_image(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.img);
	return (1);
}

int	fdf_draw(void)
{
	t_vector	*v;
	int			x;
	int			y;

	x = 0;
	y = 0;
	if ((init_image()) < 0)
		return (0);
	mlx_draw_background();
	while (y < get_fdf(0)->size_map.y)
	{
		while (x < get_fdf(0)->size_map.x)
		{
			v = get_projection(x, y);
			if (!(v))
				return (0);
			mlx_draw_wireframe(v[0], v[1], v[2], v[3]);
			free(v);
			++x;
		}
		x = 0;
		++y;
	}
	return (fdf_end_draw());
}
