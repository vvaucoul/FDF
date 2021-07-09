/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:14:54 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 16:46:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
** Fix les maps incomplètes pour éviter de connecter les bords au premier node
*/

void	fill_map(t_fvector **m, size_t x, size_t y, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		(*m)->x = x;
		(*m)->y = y;
		(*m)->z = 0;
		(*m)->color = 0;
		++i;
	}
}
