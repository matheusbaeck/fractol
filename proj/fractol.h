/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:00:26 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/10/25 01:56:00 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <complex.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

enum			e_main_errors
{
	// MAIN
	MLX_ERROR = 1,
	EXEC_FAIL = 3,
	// INIT_ALL
	FEW_ARGUMENTS = 11,
	MALLOC_FAIL_PARENT = 21,
	// INIT_PIPES
	MALLOC_FAIL_PTRCHILD = 131,
	MALLOC_FAIL_CHILD = 232,
	OPEN_PIPE = 332,
	OPEN_FILE = 432
};

enum			e_keys
{
	XK_Escape = 53,
	XK_w = 13,
	XK_s = 1,
	XK_d = 2,
	XK_a = 0,
	XK_Left = 123,
	XK_Right = 124,
	XK_Down = 125,
	XK_Up = 126,
	XK_k = 40,
	XK_l = 37,
	XK_Page_Up = 116,
	XK_Page_Down = 121,
	XK_c = 8,
	XK_space = 49,
	XK_p = 35,
	XK_i = 34,
	XK_o = 31,
	XK_u = 32,
	XK_t = 17,
	XK_y = 16,
	XK_n = 45,
	XK_m = 46,
	XK_x = 7
};

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_cartesian
{
	double		xo;
	double		xf;
	double		yo;
	double		yf;
	double		x_var;
	double		y_var;
}				t_cartesian;

typedef struct s_fractol
{
	double		z[2];
	double		c[2];
	int			resol;
	double		z_speed;
	double		m_speed;
	double		scale;
	int			axis;
	int			colour_hue;
	int			colour_saturation;
	int			colour_value;
	int			click_alowed;
	int			pow;
}				t_fractol;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			cur_img;
	t_img		img;
	t_cartesian	cart;
	t_fractol	frctl;
}				t_data;

typedef struct s_color
{
	double		h;
	double		s;
	double		v;
	double		c;
	double		x;
	double		m;
	double		r;
	double		g;
	double		b;
	int			red;
	int			green;
	int			blue;
}				t_color;

//MAIN
int				get_entry(int argc, char **argv);
int				init(t_data *data);
void			set_hooks(t_data *data);
//RENDER
void			img_pix_put(t_img *img, int x, int y, unsigned int color);
double			set_xy(t_cartesian *cart, double *xy, int i, int j);
int				fnz(double z[2], double c[2], int n, int pow);
int				render_fractol(t_data *dt);
int				render(t_data *data);
//HANDLER
void			get_variation_xy(t_data *data);
int				handle_keypress(int keysym, t_data *data);
int				handle_keypress_two(int keysym, t_data *data);
int				handle_keypress_three(int keysym, t_data *data);
int				handle_keypress_four(int keysym, t_data *data);
int				handle_keypress_five(int keysym, t_data *data);
int				handle_keypress_six(int keysym, t_data *data);
int				handle_keyrelease(int keysym, t_data *data);
int				handle_mouse(int button, int x, int y, t_data *data);
int				handle_mouse_two(int button, int x, int y, t_data *data);
//UTILS
void			set_cartesian_plan(t_cartesian *cart, t_cartesian temp);
void			set_fractol(t_fractol *frctl, t_fractol temp);
int				render_axis(t_data *dt);
int				handle_hooks(int keysym, t_data *data);
int				handle_mouse_hooks(int button, int x, int y, t_data *data);
//COLOR
void			get_rgb(t_color *color);
void			get_rgb_two(t_color *color);
int				hsv_to_rgb(int hue, int saturation, int value);

#endif
