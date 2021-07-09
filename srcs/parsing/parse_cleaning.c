/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cleaning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:31:29 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 16:41:33 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	is_bad_char(char c)
{
	static char	bad_c[5] = {'\t', '\r', '\f', '\v', 0};
	size_t		i;

	i = 0;
	while (bad_c[i])
	{
		if (bad_c[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static void	update_cleaning(char *str, size_t *i)
{
	while (str[*i] && is_bad_char(str[*i])
		&& (str[*i] == ' ' && str[*i + 1] == ' '))
		++(*i);
	while (str[*i] && (str[*i] == ' ' && str[*i + 1] == ' '))
		++(*i);
}

char	*parse_cleaning(char *const str)
{
	char	*nstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(ft_memret((void **)&nstr, sizeof(char), ft_strlen(str))))
		return (NULL);
	while (str[i])
	{
		nstr[j] = str[i];
		update_cleaning(str, &i);
		++j;
		++i;
	}
	free(str);
	return (nstr);
}
