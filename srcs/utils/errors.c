/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:28:36 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 20:18:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	error(char *str)
{
	ft_putstr("Error : ");
	ft_putstr(str);
}

int	return_error(char *str, int code)
{
	error(str);
	return (code);
}

int	exit_error(char *str, int code)
{
	error(str);
	exit(code);
}
