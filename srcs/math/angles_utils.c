/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:55:44 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 15:55:28 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

double	rad_to_deg(double radian)
{
	return (radian * 180 / M_PI);
}

double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}
