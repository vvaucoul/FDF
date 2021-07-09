/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:07:14 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:25:59 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	*ft_bzero(void *s, size_t n)
{
	char	*t;

	t = s;
	while (n)
	{
		*t = 0;
		++t;
		--n;
	}
	return (s);
}

void	*ft_memalloc(size_t size, size_t len)
{
	void	*ptr;

	ptr = malloc(size * (len + 1));
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, size * (len + 1));
	return (ptr);
}
