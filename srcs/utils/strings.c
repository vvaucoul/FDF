/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:50:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:29:25 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

char	*ft_strjoin(char *s1, char *s2, int frees1, int frees2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!(str))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		++j;
	}
	str[i + j] = 0;
	if (frees1)
		free(s1);
	if (frees2)
		free(s2);
	return (str);
}

char	*ft_charjoin(char *s1, char c, int frees1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!(str))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	str[i] = c;
	str[i + 1] = 0;
	if (frees1)
		free(s1);
	return (str);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if ((ptr) == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
