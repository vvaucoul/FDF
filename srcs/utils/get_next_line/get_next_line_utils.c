/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:27:31 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 12:08:34 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/get_next_line.h"

void	ft_strmove(char *s1)
{
	char	*tmp;
	char	*base;

	base = s1;
	tmp = s1;
	while (*tmp)
		tmp++;
	tmp++;
	while (*tmp)
		*s1++ = *tmp++;
	*s1 = *tmp;
	s1 = base;
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*t;

	t = (unsigned char *)b;
	while (len--)
		*(t++) = (unsigned char)c;
	return (b);
}
