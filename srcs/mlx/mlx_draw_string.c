/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:50:25 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 16:07:10 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	mlx_draw_string(t_vector pos, char *str, int color)
{
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		pos.x, pos.y, color, str);
}
