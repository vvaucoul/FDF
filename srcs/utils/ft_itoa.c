/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 00:12:45 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:25:45 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	n_lenght(int n)
{
	int	nsize;

	nsize = 0;
	if (n > -2147483648 && n < 0)
	{
		++nsize;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	while (n >= 1)
	{
		n /= 10;
		++nsize;
	}
	return (nsize);
}

static int	is_min_int(int n, char **str)
{
	if (n != -2147483648)
		return (0);
	*str = ft_strdup("-2147483648");
	return (1);
}

static char	*end(int isneg, char *str, int size)
{
	if (isneg)
		str[0] = '-';
	str[size] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*str;
	int		isneg;

	size = n_lenght(n);
	str = malloc(sizeof(char) * (n_lenght(n) + 1));
	if ((str) == NULL)
		return (NULL);
	if (is_min_int(n, &str) == 1)
		return (str);
	isneg = *(int *)ft_ternary((int []){1},
			(int []){0}, (n >= -2147483647 && n < 0));
	if (isneg == 1)
		n *= -1;
	i = *(int *)ft_ternary((int []){1}, (int []){1}, isneg);
	while (size - i >= 0)
	{
		str[size - i] = n % 10 + 48;
		n /= 10;
		++i;
	}
	return (end(isneg, str, size));
}
