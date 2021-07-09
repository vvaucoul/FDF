/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:45:03 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:14:47 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	loading(size_t i, char *str)
{
	size_t	ci;

	ci = 0;
	ft_putstr("\r");
	while (ci < (ft_strlen(str) + 3))
	{
		ft_putstr(" ");
		++ci;
	}
	ft_putstr(str);
	if ((i > 100))
		ft_putstr("...");
	else if ((i > 50))
		ft_putstr("..");
	else
		ft_putstr(".");
}

void	skip_non_digit(char *str, size_t *i)
{
	while (str[*i] && !ft_isdigit(str[*i]) && str[*i] != '\n')
		++(*i);
}

/*
** UTILS
*/

static void	init_get_size_map(size_t *i, size_t *x, size_t *y, size_t *mx)
{
	*i = 0;
	*x = 0;
	*y = 0;
	*mx = 0;
}

size_t	*get_size_map(char *str)
{
	size_t	i;
	size_t	x;
	size_t	y;
	size_t	mx;
	size_t	*res;

	init_get_size_map(&i, &x, &y, &mx);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			++y;
			if (x > mx)
				mx = x;
			x = 0;
		}
		++x;
		++i;
	}
	res = malloc(sizeof(size_t) * 3);
	res[0] = mx + 1;
	res[1] = y + 1;
	return (res);
}

int	check_extension(char *filename)
{
	char	nstr[4096];
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ft_fill_memory(nstr, 4096, 0);
	while (filename[i])
	{
		if (filename[i] == '.')
			break ;
		++i;
	}
	while (filename[i])
	{
		nstr[j] = filename[i];
		++i;
		++j;
	}
	if (!(ft_strcmp(nstr, ".fdf")))
		return (1);
	return (0);
}
