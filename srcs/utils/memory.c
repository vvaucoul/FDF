/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:38:41 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:28:20 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

char	*ft_calloc(size_t size, size_t nb)
{
	char	*m;
	size_t	i;

	i = 0;
	m = (char *)malloc(sizeof(size) * (nb + 1));
	if (!(m))
		return (NULL);
	else
	{
		while (i <= nb)
		{
			m[i] = 0;
			++i;
		}
	}
	return (m);
}

void	*ft_fill_memory(void *ptr, size_t nb, char value)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)ptr;
	while (i < nb)
	{
		str[i] = value;
		++i;
	}
	ptr = str;
	return (str);
}
