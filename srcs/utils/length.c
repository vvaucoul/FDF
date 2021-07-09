/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:52:01 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:28:03 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

size_t	*ft_tab_len(char **tab)
{
	size_t	*ret;
	size_t	x;
	size_t	cx;
	size_t	y;

	x = 0;
	cx = 0;
	y = 0;
	while (tab[y])
	{
		while (tab[y][x])
			++x;
		if (x > cx)
			cx = x;
		x = 0;
		++y;
	}
	ret = (size_t []){x, y};
	return (ret);
}
