/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:23:16 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:08:21 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static char	*init_file(int fd)
{
	char	*str;
	size_t	i;
	char	*gnl_buffer;

	i = 0;
	str = ft_strdup("");
	while ((get_next_line(fd, &gnl_buffer)) > 0)
	{
		str = ft_strjoin(str, gnl_buffer, 1, 1);
		str = ft_strjoin(str, "\n", 1, 0);
		loading(i++, "\rLoading Map");
		i = *(size_t *)ft_ternary((size_t []){0}, (size_t []){i}, i > 150);
	}
	free(gnl_buffer);
	if (!(str))
		return (NULL);
	else if (!str[0])
		return (NULL);
	return (str);
}

int	parse_file(char *filename)
{
	char	*str;
	int		fd;

	if (!check_extension(filename))
		return (-1);
	get_fdf(1);
	fd = open(filename, O_RDONLY);
	if (!(fd))
		return (-1);
	str = init_file(fd);
	if (!(str))
		return (-1);
	str = parse_cleaning(str);
	init_map(str);
	close(fd);
	free(str);
	apply_colors();
	ft_putstr("\n");
	return (0);
}
