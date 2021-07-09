/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multijoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 00:19:43 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:27:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static size_t	ft_full_tablen(char **tab)
{
	size_t	i;
	size_t	max_x;

	i = 0;
	max_x = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > max_x)
			max_x = ft_strlen(tab[i]);
		++i;
	}
	return (i * max_x);
}

static void	ft_multijoin_assign_tab(char *nstr, char **tab, int j)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (tab[i])
	{
		while (tab[i][k])
		{
			nstr[j] = tab[i][k];
			++j;
			++k;
		}
		nstr[j] = 0;
		++i;
		k = 0;
	}
}

char	*ft_multijoin(char **tab)
{
	char	*nstr;
	size_t	i;

	i = 0;
	nstr = ft_memalloc(sizeof(char), ft_full_tablen(tab));
	if (!(nstr))
		return (NULL);
	ft_multijoin_assign_tab(nstr, tab, i);
	return (nstr);
}
