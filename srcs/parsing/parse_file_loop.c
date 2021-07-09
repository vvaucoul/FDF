/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:04:07 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:11:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/*
** LOOP PARSING
*/

static int	init_map_init(t_parsing	*p, char *str)
{
	size_t	*size_map;

	size_map = get_size_map(str);
	*p = (t_parsing){0, 0, 0, 0, ft_strlen(str), size_map, size_map[1] - 1};
	get_fdf(0)->map = (t_fvector **)ft_memalloc(sizeof(t_fvector *),
		(*p).size_map[0] * (*p).size_map[1]);
	if (!(get_fdf(0)->map))
		return (-1);
	get_fdf(0)->map[(*p).y] = (t_fvector *)ft_memalloc(sizeof(t_fvector),
		(*p).size_map[0]);
	if (!(get_fdf(0)->map[(*p).y]))
		return (-1);
	if (!(ft_fill_memory(get_fdf(0)->map[(*p).y], (*p).size_map[0], 0)))
		return (-1);
	fill_map(&get_fdf(0)->map[(*p).y], (*p).x, (*p).y, (*p).size_map[0]);
	skip_non_digit(str, &(*p).i);
	return (0);
}

static int	init_map_loop_next(t_parsing *p, char *str)
{
	if (str[(*p).i] == '\n')
	{
		get_fdf(0)->size_map.x = *(int *)ft_ternary((int []){(int)(*p).x},
			(int []){(int)get_fdf(0)->size_map.x},
			((int)(*p).x > get_fdf(0)->size_map.x));
		++(*p).y;
		(*p).x = 0;
		get_fdf(0)->map[(*p).y] = (t_fvector *)ft_memalloc(sizeof(t_fvector),
			(*p).size_map[0]);
		if (!(get_fdf(0)->map[(*p).y]))
			return (-1);
		if (!(ft_fill_memory(get_fdf(0)->map[(*p).y], (*p).size_map[0], 0)))
			return (-1);
		fill_map(&get_fdf(0)->map[(*p).y], (*p).x, (*p).y, (*p).size_map[0]);
		++(*p).i;
	}
	else
		++(*p).x;
	return (0);
}

static int	init_map_loop(t_parsing *p, char *str)
{
	char	*tmp;

	while ((*p).i < (*p).imax)
	{
		get_fdf(0)->map[(*p).y][(*p).x]
		= init_vector_map(str, &(*p).i, (*p).x, (*p).y);
		get_fdf(0)->map[(*p).y][(*p).x + 1]
		= (t_fvector){(*p).x, (*p).y, get_fdf(0)->map[(*p).y][(*p).x].z, 0};
		init_map_loop_next(p, str);
		skip_non_digit(str, &(*p).i);
		tmp = ft_strdup("\rInitialise Map, ");
		tmp = ft_strjoin(tmp, ft_itoa((*p).y), 1, 1);
		tmp = ft_strjoin(tmp, "/", 1, 0);
		tmp = ft_strjoin(tmp, ft_itoa((*p).ymax), 1, 1);
		loading((*p).ld++, tmp);
		free(tmp);
		(*p).ld = *(size_t *)ft_ternary((size_t []){0},
				(size_t []){(*p).ld}, (*p).ld > 150);
	}
	return (0);
}

static int	init_map_end(t_parsing *p)
{
	free(get_fdf(0)->map[(*p).y]);
	get_fdf(0)->map[(*p).y] = NULL;
	--(*p).y;
	get_fdf(0)->size_map.y = (*p).y;
	free((*p).size_map);
	return (0);
}

int	init_map(char *str)
{
	t_parsing	p;

	init_map_init(&p, str);
	init_map_loop(&p, str);
	init_map_end(&p);
	return (0);
}
