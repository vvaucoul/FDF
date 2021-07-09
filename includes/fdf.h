/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:17:51 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/07/08 10:00:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>

# include <mlx.h>

/*
**	KEYS LINUX
*/

# define KEY_INCREASE_Z 106
# define KEY_DECREASE_Z 104
# define KEY_MOVEMENT_FORWARD 119
# define KEY_MOVEMENT_BACKWARD 115
# define KEY_MOVEMENT_RIGHT 100
# define KEY_MOVEMENT_LEFT 97
# define KEY_MOVEMENT_ROTATION_LEFT 65361
# define KEY_MOVEMENT_ROTATION_RIGHT 65363
# define KEY_MOVEMENT_ROTATION_UP 65362
# define KEY_MOVEMENT_ROTATION_DOWN 65364
# define KEY_INCREASE_FOV 118
# define KEY_DECREASE_FOV 98
# define KEY_USER_INTERFACE 112
# define KEY_RESET_VIEW 114
# define KEY_SWITCH_ROTATION 110
# define KEY_FORCE_COLOR 99
# define KEY_QUIT 65307

/*
**	MAC INPUTS
**
** # define KEY_INCREASE_Z 4
** # define KEY_DECREASE_Z 38
** # define KEY_MOVEMENT_FORWARD 13
** # define KEY_MOVEMENT_BACKWARD 1
** # define KEY_MOVEMENT_RIGHT 2
** # define KEY_MOVEMENT_LEFT 0
** # define KEY_MOVEMENT_ROTATION_LEFT 123
** # define KEY_MOVEMENT_ROTATION_RIGHT 124
** # define KEY_MOVEMENT_ROTATION_UP 126
** # define KEY_MOVEMENT_ROTATION_DOWN 125
** # define KEY_INCREASE_FOV 9
** # define KEY_DECREASE_FOV 11
** # define KEY_USER_INTERFACE 35
** # define KEY_RESET_VIEW 15
** # define KEY_SWITCH_ROTATION 45
** # define KEY_FORCE_COLOR 8
** # define	KEY_QUIT 53
** # include "../minilibx_linux/mlx.h"
*/

/*
** # include <stdio.h>
*/

# include "get_next_line.h"

# define RES_X 1280
# define RES_Y 720

# define WINDOW_TITLE "FDF"

# define ISOMETRIC_ANGLE 0.523599

# define MAP_Z_MAX 128
# define MAP_Z_MIN -128

# define RLOCATION_X 2.385398
# define RLOCATION_Y 1.600
# define RLOCATION_Z -0.7853981633973

# define CAMERA_ROTATION_ANGLE 0.05
# define CAMERA_MOVEMENT_SPEED 3.0f

# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_BLUE 0x0000FF

# define COLOR_UI_CONTROLS 0x66B0FA
# define COLOR_UI_ANGLES 0xD12E2E
# define COLOR_UI_HEIGHT 0xF45C1B

# define UI_FONT_SIZE 10
# define UI_HEADER "FDF, 42 PROJECT - by vvaucoul"

# define SCALE_MIN	1
# define SCALE_MAX	100

# define NB_INPUTS 8

# define FDF_COLOR_LS_00	0x2E3FFF
# define FDF_COLOR_LS_01	0x26EB4A
# define FDF_COLOR_LS_02	0x5C391C
# define FDF_COLOR_LS_03	0xEDE3DA

# define PARSING_DIGITS		"0123456789ABCDEF"

/*
**		UTILS
*/

typedef struct s_parsing
{
	size_t		i;
	size_t		x;
	size_t		y;
	size_t		ld;
	size_t		imax;
	size_t		*size_map;
	size_t		ymax;
}				t_parsing;

typedef struct s_dinterp
{
	double		vi;
	double		vf;
	double		delta_time;
	int			seg;
	int			i;
}				t_dinterp;

typedef struct s_clamp
{
	int			old_value;
	int			old_min;
	int			old_max;
	int			new_min;
	int			new_max;
}				t_clamp;

typedef struct s_event
{
	int			reset_view;
	int			reset_height;
	int			reset_cam_location;
	int			reset_cam_rlocation;
}				t_event;

typedef struct s_vector
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_vector;

typedef struct s_fvector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_fvector;

typedef struct s_reset
{
	size_t		count;
	double		nvx;
	double		nvy;
	double		nvz;
}				t_reset;

/*
**		CORE
*/

typedef struct s_camera
{
	t_fvector	location;
	t_fvector	r_location;
	double		fov;
	double		angle;
}				t_camera;

typedef struct s_draw
{
	double		draw_scale;
	double		draw_z_scale;
}				t_draw;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*data_addr;

	int			bits_per_pixel;
	int			size_line;
	int			endian;

	int			res_x;
	int			res_y;
}				t_mlx;

typedef struct s_fdf
{
	t_mlx		mlx;
	t_camera	camera;

	t_fvector	**map;
	t_vector	size_map;
	t_draw		draw;
	t_event		event;
	int			draw_ui;
	int			rotate_z;
	int			force_color;
}				t_fdf;

/*
**		PARSING
*/

int			parse_file(char *filename);
int			parsing_assign_color(char *str, int base);
char		*parse_cleaning(char *const str);
int			apply_colors(void);
int			fix_parsing(void);

int			init_map(char *str);

/*
** PARSING UTILS
*/

void		loading(size_t i, char *str);
void		skip_non_digit(char *str, size_t *i);
void		fill_map(t_fvector **m, size_t x, size_t y, size_t len);
void		loading(size_t i, char *str);
void		skip_non_digit(char *str, size_t *i);
void		fill_map(t_fvector **m, size_t x, size_t y, size_t len);

t_fvector	init_vector_map(char *str, size_t *start, size_t x, size_t y);
size_t		*get_size_map(char *str);
int			check_extension(char *filename);

/*
**		MLX
*/

int			init_mlx(void);
void		mlx_draw_pixel(int x, int y, int color);
int			mlx_draw_line(t_vector start, t_vector end);
int			mlx_color(int const red, int const green, int const blue);
void		mlx_draw_wireframe(t_vector top_left, t_vector top_right,
				t_vector bottom_left, t_vector bottom_right);
void		mlx_draw_string(t_vector pos, char *str, int color);
void		mlx_draw_background(void);
int			init_image(void);
void		user_interface(void);

/*
**	EVENT
*/

int			fdf_event(void);
int			evnt_reset_cam_rlocation(int reset, t_fvector new);
int			evnt_reset_cam_location(int reset, t_fvector new);
int			evnt_reset_height(int reset);
int			evnt_reset_view(int reset);

int			fdf_event_check_values(void);
int			evnt_reset_height(int reset);
int			evnt_reset_cam_location(int reset, t_fvector new);
int			evnt_reset_cam_rlocation(int reset, t_fvector new);

/*
**		CAMERA
*/

void		init_camera(void);
t_fvector	get_init_camera_location(void);
void		rotate_xyz(t_vector *p);

/*
**		INPUTS
*/

int			input_fdf_pressed(int key, void *param);
int			input_fdf_released(int key, void *param);
void		inputs_camera(int key);

int			input_quit(int key, void *param);

/*
**		CORE
*/

t_fdf		*get_fdf(int init);
int			fdf_draw(void);
void		fdf_clean(void);
int			fdf_color(t_vector current, t_vector start,
				t_vector end, t_vector delta);
int			fdf_default_color(int z);
void		free_fdf(void);
void		fdf_force_color(void);

/*
**		MATH
*/

void		projection_isometric(t_vector *p);
t_fvector	projection_isometric_float(t_fvector p);
double		rad_to_deg(double radian);
double		deg_to_rad(double deg);
void		clamp_int(int *val, int min, int max);
void		clamp_double(double *val, double min, double max);
int			nearly_equal(double *val, double min, double max, double lock);
double		ft_dinterp(t_dinterp d);
void		bresenham(t_vector start, t_vector end);
int			int_range_clamped(t_clamp c);
int			get_scale_map(void);

/*
**		UTILS
*/

void		ft_putchar(char c);
void		ft_putstr(char *str);

void		error(char *str);
int			return_error(char *str, int code);
int			exit_error(char *str, int code);

size_t		ft_strlen(char *str);
size_t		*ft_tab_len(char **tab);

char		*ft_strjoin(char *s1, char *s2, int frees1, int frees2);
char		*ft_charjoin(char *s1, char c, int frees1);

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
char		*ft_strdup(char *s1);

char		*ft_calloc(size_t size, size_t nb);
void		*ft_fill_memory(void *ptr, size_t nb, char value);

char		*ft_itoa(int n);
char		*ft_multijoin(char **tab);

void		*ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size, size_t len);
int			ft_memret(void **ptr, size_t size, size_t len);

int			ft_islower(int c);
int			ft_toupper(int c);
int			ft_isspace(int c);

void		*ft_ternary(void *f1, void *f2, int condition);
int			ft_strcmp(const char *s1, const char *s2);

#endif
