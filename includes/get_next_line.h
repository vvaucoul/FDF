/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:27:29 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/08 09:59:01 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# include "fdf.h"

# define BUFFER_SIZE	8192

/*
** utils
*/

void		ft_strmove(char *s1);
void		*ft_memset(void *b, int c, size_t len);

/*
** gnl
*/

int			get_next_line(int fd, char **line);
int			set_line(char *str, char **line, int n_read, int fd);
int			read_file(int fd, char *str, int n_read, char **line);

#endif
