/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:05:29 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 21:08:57 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
** INIT VECTOR MAP
*/

int	init_vector_map_next(char *nstr, char *str, char *color, size_t *start)
{
	size_t		i;

	i = 0;
	while (str[*start] && ft_isdigit(str[*start]))
	{
		nstr[i] = str[*start];
		++*start;
		++i;
	}
	nstr[i] = 0;
	if (str[*start] == ',')
	{
		i = 0;
		++(*start);
		ft_fill_memory(color, 9, 0);
		while (str[*start] && str[*start] != ' ' && str[*start] != '\n')
		{
			color[i] = str[*start];
			++(*start);
			++i;
		}
		color[i] = 0;
	}
	return (0);
}

t_fvector	init_vector_map(char *str, size_t *start, size_t x, size_t y)
{
	t_fvector	vec;
	char		nstr[512];
	char		*tmp;
	char		color[9];

	ft_fill_memory(color, 9, 0);
	init_vector_map_next(nstr, str, color, start);
	tmp = ft_strdup(nstr);
	vec.x = x;
	vec.y = y;
	vec.z = ft_atoi(tmp);
	free (tmp);
	if (color[0] != 0)
		vec.color = parsing_assign_color(color, 16);
	else
		vec.color = 0xFFFFFF;
	return (vec);
}
