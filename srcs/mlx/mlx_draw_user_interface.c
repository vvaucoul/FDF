/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_user_interface.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:43:08 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/07 21:08:12 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ui_controls(void)
{
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50, COLOR_UI_CONTROLS,
		"MOVEMENTS : W, A, S, D");
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 1), COLOR_UI_CONTROLS,
		"ZOOM : V, B");
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 2), COLOR_UI_CONTROLS,
		"ROTATION : Arrows, UP/DOWN/RIGHT/LEFT");
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 3), COLOR_UI_CONTROLS,
		"HEIGHT : H, J");
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 4), COLOR_UI_CONTROLS,
		"RESET VIEW : R");
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 5), COLOR_UI_CONTROLS,
		"HIDE UI : P");
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 6), COLOR_UI_CONTROLS,
		"SWITCH ROTATION : N");
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 7), COLOR_UI_CONTROLS,
		"FORCE COLOR : C");
}

static void	ui_angle(void)
{
	char	*tmp;
	char	*rloc;

	rloc = ft_itoa(rad_to_deg(get_fdf(0)->camera.r_location.x));
	tmp = ft_strjoin("RX : ", rloc, 0, 1);
	tmp = ft_strjoin(tmp, "°", 1, 0);
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 16), COLOR_UI_ANGLES, tmp);
	free(tmp);
	rloc = ft_itoa(rad_to_deg(get_fdf(0)->camera.r_location.y));
	tmp = ft_strjoin("RY : ", rloc, 0, 1);
	tmp = ft_strjoin(tmp, "°", 1, 0);
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 17), COLOR_UI_ANGLES, tmp);
	free(tmp);
	rloc = ft_itoa(rad_to_deg(get_fdf(0)->camera.r_location.z));
	tmp = ft_strjoin("RZ : ", rloc, 0, 1);
	tmp = ft_strjoin(tmp, "°", 1, 0);
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 18), COLOR_UI_ANGLES, tmp);
	free(tmp);
}

static void	ui_info(void)
{
	char	*tmp;

	if (get_fdf(0)->rotate_z)
		tmp = ft_strdup("ROTATION Mode : Z");
	else
		tmp = ft_strdup("ROTATION Mode : Y");
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 20), COLOR_UI_ANGLES, tmp);
	free(tmp);
	tmp = ft_strdup("HEIGHT SCALE : ");
	tmp = ft_strjoin(tmp, ft_itoa((int)(get_fdf(0)->draw.draw_z_scale * 100)),
			1, 1);
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 10), COLOR_UI_HEIGHT, tmp);
	free(tmp);
}

static void	ui_foreground(void)
{
	char	*tmp;
	char	*camloc;

	mlx_draw_string((t_vector){(RES_X / 2) - (ft_strlen(UI_HEADER) / 2)
		* UI_FONT_SIZE, (RES_Y / 16) / 2, 0, 0}, UI_HEADER, COLOR_WHITE);
	tmp = ft_itoa(get_fdf(0)->draw.draw_scale);
	tmp = ft_strjoin("FOV : ", tmp, 0, 1);
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 31), COLOR_UI_CONTROLS, tmp);
	free(tmp);
	camloc = ft_strjoin("CAMERA LOCATION : ", "X: ", 0, 0);
	tmp = ft_itoa(get_fdf(0)->camera.location.x);
	camloc = ft_strjoin(camloc, tmp, 1, 1);
	camloc = ft_strjoin(camloc, " Y: ", 1, 0);
	tmp = ft_itoa(get_fdf(0)->camera.location.y);
	camloc = ft_strjoin(camloc, tmp, 1, 1);
	camloc = ft_strjoin(camloc, " Z: ", 1, 0);
	tmp = ft_itoa(get_fdf(0)->camera.location.z);
	camloc = ft_strjoin(camloc, tmp, 1, 1);
	camloc = ft_strjoin(camloc, "", 1, 0);
	mlx_string_put(get_fdf(0)->mlx.mlx, get_fdf(0)->mlx.window,
		UI_FONT_SIZE, 50 + ((UI_FONT_SIZE * 2) * 32),
		COLOR_UI_CONTROLS, camloc);
	free(camloc);
}

void	user_interface(void)
{
	if (!get_fdf(0)->draw_ui)
	{
		mlx_draw_string((t_vector){(RES_X / 2) - (ft_strlen(UI_HEADER) / 2)
			* UI_FONT_SIZE, (RES_Y / 16) / 2, 0, 0}, UI_HEADER, COLOR_WHITE);
		return ;
	}
	ui_controls();
	ui_foreground();
	ui_angle();
	ui_info();
}
