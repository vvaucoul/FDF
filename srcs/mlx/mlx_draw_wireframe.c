/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_wireframe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:13:26 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 16:37:17 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
** bresenham(top_left, top_right);
** bresenham(top_left, bottom_left);
** bresenham(top_right, bottom_right);
** bresenham(bottom_left, bottom_right);
*/

void	mlx_draw_wireframe(t_vector top_left,
t_vector top_right, t_vector bottom_left, t_vector bottom_right)
{
	mlx_draw_line(top_left, top_right);
	mlx_draw_line(top_left, bottom_left);
	mlx_draw_line(top_right, bottom_right);
	mlx_draw_line(bottom_left, bottom_right);
}
