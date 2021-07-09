/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:15:58 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:21:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	skipuselesschar(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t'
		|| str[i] == '\n'
		|| str[i] == '\v'
		|| str[i] == '\r'
		|| str[i] == '\f'
		|| str[i] == ' ')
		++i;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		isneg;
	size_t	i;

	result = 0;
	i = skipuselesschar(str);
	isneg = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		isneg = *(int *)ft_ternary((int []){1}, (int []){0}, str[i] == '-');
		++i;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		++i;
	}
	if (isneg == 1)
		return (result * -1);
	return (result);
}
