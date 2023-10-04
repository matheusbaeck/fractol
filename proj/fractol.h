/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 02:00:26 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/10/04 21:49:26 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <complex.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

enum	e_main_errors {
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

enum	e_keys {
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
	XK_x = 7
};

// enum
// {
// 	ON_KEYDOWN = 2,
// 	ON_KEYUP = 3,
// 	ON_MOUSEDOWN = 4,
// 	ON_LCLICK = 1,
// 	ON_RCLICK = 2,
// 	ON_MOUSEUP = 5,
// 	ON_MOUSEMOVE = 6,
// 	ON_EXPOSE = 12,
// 	ON_DESTROY = 17,
// 	J = 38,
// 	M = 46,
// 	SPACE = 49,
// 	L_SHIFT = 257,
// 	R_SHIFT = 258,
// };

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_cartesian	
{
	double	xo;
	double	xf;
	double	yo;
	double	yf;
	double	x_var;
	double	y_var;
}	t_cartesian;

typedef struct s_fractol
{
	double	z[2];
	double	c[2];
	int		resol;
	double	z_speed;
	double	m_speed;
	double	scale;
	int		axis;
	int		colour_hue;
	int		colour_saturation;
	int		colour_value;
}	t_fractol;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			cur_img;
	t_img		img;
	t_cartesian	cart;
	t_fractol	frctl;
}	t_data;

//RENDER
void	img_pix_put(t_img *img, int x, int y, unsigned int color);
double	set_xy(t_cartesian *cart, double *xy, int i, int j);
int		fnz(double z[2], double c[2], int n);
int		render_mandelbrot(t_data *dt);
int		render(t_data *data);

#endif
