/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:13:20 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 21:33:36 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_error("Bad arguments\n\tusage : ./fdf \"map\"\n", -1);
	if ((parse_file(argv[1])))
		exit_error("Invalid map\n", -1);
	if (!(init_mlx()))
		return (exit_error("MLX Init Error", -1));
	init_camera();
	if (!(fdf_draw()))
		return (exit_error("FDF Error", -1));
	mlx_hook(get_fdf(0)->mlx.window, 2, (1L << 0), input_fdf_pressed, NULL);
	mlx_hook(get_fdf(0)->mlx.window, 3, (1L << 1), input_fdf_released, NULL);
	mlx_hook(get_fdf(0)->mlx.window, 17, (1L << 17), input_quit, NULL);
	mlx_loop_hook(get_fdf(0)->mlx.mlx, fdf_event, NULL);
	mlx_loop(get_fdf(0)->mlx.mlx);
	return (0);
}

/*
** 	//free_fdf();
** 	//exit(0);
*/
