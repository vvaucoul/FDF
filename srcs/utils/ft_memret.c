/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:48:02 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:26:13 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
** Malloc et return 0 si malloc echoue (contourner norme v3)
*/

int	ft_memret(void **ptr, size_t size, size_t len)
{
	*ptr = ft_memalloc(size, len);
	if (!(*ptr))
		return (0);
	return (1);
}
