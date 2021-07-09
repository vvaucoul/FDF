/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:12:00 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 15:55:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
**	Double Interpolation
**
**	Usleep usage for bonus (needed for delta time)
*/

double	ft_dinterp(t_dinterp d)
{
	double	ret;

	ret = d.vi + d.i * (d.vf - d.vi) / d.seg;
	usleep(d.delta_time);
	return (ret);
}
